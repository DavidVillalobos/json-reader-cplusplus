/*
    File: Json.cpp
    Author: David Villalobos
    Date: 2021-07-17
    Description: Implementation of class Json
    to represent a object or an array.
*/
#include"Json.h"

Json::Json(std::string path) : Element("") {
    this->path = path;
    if (path != "") {
        std::ifstream f(path);
        std::string file;
        if (f.good()) {
            std::string aux;
            while (!f.eof()) {
                std::getline(f, aux);
                file += aux;
            }
            ObjectFromString(this, file);
        }
        else {
            throw std::runtime_error("Could not open file " + path);
        }
    }
}

Json& Json::operator=(const Json& other)
{
    this->path = other.path;
    for (auto x : other.value) {
        Property* p = dynamic_cast<Property*>(x.second);
        if (p) {
            this->value[x.first] = new Property(x.first, p->getValue()); 
        }
        else {
            Json* temp1 = dynamic_cast<Json*>(x.second);
            if (temp1) {
                Json* temp2 = new Json(*temp1);
                this->value[x.first] = temp2;
            }
        }
    }
    return *this;
}

Json::Json(const Json& other) : Element("") {
    this->path = other.path;
    for (auto x : other.value) {
        Property* p = dynamic_cast<Property*>(x.second);
        if (p) {
            this->value[x.first] = new Property(*p); 
        }
        else {
            Json* temp1 = dynamic_cast<Json*>(x.second);
            if (temp1) {
                Json* temp2 = new Json(*temp1);
                this->value[x.first] = temp2;
            }
        }
    }
}

std::string Json::sliceText(std::string& text, char begin, char end) {
    text.erase(0, text.find(begin) + 1);
    int cant = 1; 
    size_t i = 0;
    for (; i < text.length(); i++) {
        if (text[i] == begin) { cant++; }
        else if (text[i] == end) { cant--; }
        if (cant == 0) { break; }
    }
    std::string obj = text.substr(0, i);
    text.erase(0, i);
    return obj;
}

void Json::ObjectFromString(Json* temp, std::string object) {
    std::smatch match;
    std::regex r("\"([\\w0-9. ]+)\"[ ]*:[ ]*\"?([\\w0-9. ]+)\"?");
    std::smatch::iterator i;
    std::string name;
    while (regex_search(object, match, r)) {
        i = match.begin();
        i++;
        //std::cout << "Group #1 Name: " << i->str() << std::endl;
        name = i->str();
        i++;
        if (i->str() != " ") {
            temp->value[name] = new Property(name, i->str());
            //std::cout << "Group #2 Prop: " << i->str() << std::endl;
            object = match.suffix().str();
        }
        else {
            Json* aux = new Json();
            temp->value[name] = aux;
            if (object.find("{") < object.find("[")) { // is object
                ObjectFromString(aux, sliceText(object, '{', '}'));
                //std::cout << "Obj: " << sliceText(object, '{', '}') << std::endl;
            }
            else if (object.find("[") != std::string::npos){ // is array
                ArrayFromString(aux, sliceText(object, '[', ']'));
                //std::cout << "Arr: " << sliceText(object, '[', ']') << std::endl;
            } else {
                throw std::runtime_error("Syntax error in json for property " + name);
            }
        }
    }
}

void Json::ArrayFromString(Json* temp, std::string array){
    int pos = 0;
    while (array.find("{") != std::string::npos) { // is object
        Json* aux = new Json();
        ObjectFromString(aux, sliceText(array, '{', '}'));
        temp->value[std::to_string(pos)] = aux;
        pos++;
    }
}

std::ostream& operator << (std::ostream &o,const Json &c)
{
    Property* prop = dynamic_cast<Property*>(c.value.begin()->second);
    o << prop->getValue();
    return o;
}

Json::~Json(){
    for (auto x : value) {
        delete x.second; // free memory
    }
}

std::string Json::getPath() {
    return path;
}

Json::operator std::string() {
    Element* e = value.begin()->second;
    Property* p = dynamic_cast<Property*>(e);
    Json temp;
    if (p) {
        return p->getValue();
    } else {
        return "";
    }
}

Json::operator int() {
    Element* e = value.begin()->second;
    Property* p = dynamic_cast<Property*>(e);
    Json temp;
    if (p) {
        try {
            return stoi(p->getValue());
        } catch (std::exception& err) {
            return 0;
        }
    }
    else {
        return 0;
    }
}

Json::operator float() {
    Element* e = value.begin()->second;
    Property* p = dynamic_cast<Property*>(e);
    Json temp;
    if (p) {
        try {
            return stof(p->getValue());
        }
        catch (std::exception& err) {
            return 0.0f;
        }
    }
    else {
        return 0.0f;
    }
}

Json::operator bool() {
    Element* e = value.begin()->second;
    Property* p = dynamic_cast<Property*>(e);
    Json temp;
    if (p) {
        return p->getValue() == "true";
    }
    else {
        return false;
    }
}

Json Json::operator[](const char* prop) {
    return getProperty(std::string(prop));
}

Json Json::operator[](std::string prop) {
    return getProperty(prop);
}

Json Json::operator[](int index)
{
    return getProperty(std::to_string(index));
}

Json Json::getProperty(std::string prop) {
    Element* e = value[prop];
    Property* p = dynamic_cast<Property*>(e);
    Json temp;
    if (p) {
        temp.value[prop] = new Property(*p);
    } else {
        Json* temp2 = dynamic_cast<Json*>(e);
        if (temp2) {
            temp.path = temp2->path;
            temp.value = temp2->value;
        }
    }
    return temp;
}

bool Json::operator==(const char* value) {
    std::string res = *this;
    return res == value;
}
bool Json::operator==(const std::string value) {
    return (std::string)*this == value;
}
bool Json::operator==(const int value) {
    return (int)*this == value;
}
bool Json::operator==(const float value) {
    return (float) *this == value;
}
bool Json::operator==(const bool value) {
    return (bool)*this == value;
}

bool Json::operator!=(const char* value) {
    std::string res = *this;
    return res != value;
}
bool Json::operator!=(const std::string value) {
    return (std::string)*this != value;
}
bool Json::operator!=(const int value) {
    return (int)*this != value;
}
bool Json::operator!=(const float value) {
    return (float) *this != value;
}
bool Json::operator!=(const bool value) {
    return (bool)*this != value;
}