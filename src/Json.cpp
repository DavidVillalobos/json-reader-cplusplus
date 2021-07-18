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
            Json* temp = ObjectFromString(file);
            this->value = temp->value;
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

Json* Json::ObjectFromString(std::string object) {
    Json* temp = new Json();
    
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
            if (object.find("{") < object.find("[")) { // is object
                Json* aux = ObjectFromString(sliceText(object, '{', '}'));
                temp->value[name] = aux;
                //std::cout << "Obj: " << sliceText(object, '{', '}') << std::endl;
            }
            //else { // is array
                //std::cout << "Arr: " << sliceText(object, '[', ']') << std::endl;
            //}
        }
    }

    return temp;
}

Json* Json::ArrayFromString(std::string array){
    Json* temp = new Json();
    // build object json from array
    return temp;
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
    return "GET STRING PROPERTY";
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