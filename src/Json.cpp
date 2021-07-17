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
        std::ifstream f("aja.json");
        std::string file;
        if (f.good()) {
            std::string aux;
            while (!f.eof()) {
                std::getline(f, aux);
                file += aux;
            }
        }
        else {
            throw "FAIL: File not found in path " + path;
        }
    }
}

#include<iostream>

Json Json::ObjectFromString(std::string object) {
    Json temp;
    
    std::smatch match;
    std::regex prop("\"([\\w0-9. ]+)\"[ ]*:[ ]*\"?([\\w0-9. ]+)\"?");
    std::regex obj("\"[\\w0-9]+\"[ \n\t]*:[ \\n\\t]*(\\{[\\w:, {}\\n\\t\"]*})");
    std::regex arr("\"[\\w0-9]+\"[ \n\t]*:[ \\n\\t]*(\\[[\\w:, {}\\n\\t\"]*])");
    std::smatch::iterator i;
    while (regex_search(object, match, prop)) {
        i = match.begin();
        i++;
        std::cout << "Group #1 Name: " << i->str() << std::endl;
        i++;
        if (i->str() == " ") {
            std::cout << "Group #2 Prop: " << i->str() << std::endl;
        }
        else {
            if (object.find("{") < object.find("[")) { 
                if (regex_search(object, match, obj)) {
                    i = match.begin();
                    i++;
                    std::cout << "Group #2 Obj: " << i->str() << std::endl;
                }
            }
            else { 
                if (regex_search(object, match, arr)) {
                    std::smatch::iterator j = match.begin();
                    i++;
                    std::cout << "Group #2 Arr: " << i->str() << std::endl;
                }
            }
        }
        object = match.suffix().str();
    }
    return temp;
}

Json Json::ArrayFromString(std::string array){
    Json temp;
    // build object json from array
    return temp;
}

std::ostream& operator << (std::ostream &o,const Json &c)
{
    o << "{ ";
    for (auto tuple : c.value) {
        o << tuple.second << ", ";
    }
    o << "}";
    return o;
}

Json::~Json(){
    for (auto x : value){
        delete x.second; // free memory
    }
}

std::string Json::getPath() {
    return path;
}

Json::operator std::string() {
    return "GET STRING PROPERTY";
}

Json& Json::operator[](const char* prop) {
    return *getProperty(std::string(prop));
}

Json& Json::operator[](std::string prop) {
    return *getProperty(prop);
}

Json& Json::operator[](int index)
{
    return *getProperty(std::to_string(index));
}

Json* Json::getProperty(std::string prop) {
    Element* e = value[prop];
    Property* p = dynamic_cast<Property*>(e);
    Json* temp;
    if (p) {
        temp = new Json();
        temp->value[prop] = e;
    } else {
        temp = dynamic_cast<Json*>(e);
    }
    return temp;
}