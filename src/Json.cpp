/*
    File: Json.cpp
    Author: David Villalobos
    Date: 2021-12-03
    Description: Implementation of class Json
    to represent a object or an array.
*/
#include"Json.h"

Json::Json(std::string name, std::string value) : Element(name, value){

}

Element* Json::getObject(int index){
    return value[std::to_string(index)];
}

Element* Json::getProperty(std::string prop){
    return value[prop];
}

std::ostream& operator << (std::ostream &o,const Json &c)
{
    for () {

    }
    o << c.value;
    return o;
}

Json::~Json(){
    for (auto x : value){
        delete x.second; // free memory
    }
}



Json::Json(std::string path) {
    this->path = path;
    this->regex_value_in_obj = std::regex("\"([\\w0-9. ]+)\":\"?([\\w0-9. ]+|\\[[\\w0-9. \"{}:,]+\\]|\\{[\\w0-9 .\"{}:,]+\\})\"?");
    // Bugs when debbuger (gdb) maybe not locate a file :0
    // Read a json file  
    /*
    std::ifstream f(path);
    if(f.good()){
        std::string aux;
        while (!f.eof()){
            getline(f, aux);
            file += aux;
        }
    }else{
        throw "FAIL: File not found or not load in path" + path;
    }
    // */
    file = "{\"firstName\":\"Rack\",\"lastName\":\"Jackon\",\"gender\":\"man\",\"age\":24,\"address\":{\"streetAddress\":\"126\",\"city\":\"SanJone\",\"state\":\"CA\",\"postalCode\":\"394221\"},\"phoneNumbers\":[{\"type\":\"home\",\"number\":\"7383627627\",\"example\":{\"object\":\"name\",\"value\":false}},{\"type\":\"office\",\"number\":\"8462945527\"}]}";
    // Remove endlines, tabs and black spaces (not in string)
    std::regex r("\n|\t| (?=([^\"]*\"[^\"]*\")*[^\"]*$)");
    file = std::regex_replace(file, r, "");
    this->object = loadvalueFromObject("root", file);
}

std::string Json::getObjectFromArray(std::string& arr) {
    std::string result = "";
    char simbol;
    int cant_curly_brackets = 1;
    arr.erase(0, 1); // remove first '{'
    while (true) {
        simbol = arr[0];
        arr.erase(0, 1);
        if (simbol == '{') { cant_curly_brackets++; }
        else if (simbol == '}') { cant_curly_brackets--; }
        if (cant_curly_brackets == 0) { break; }
        result += simbol;
    }
    // Remove a residue
    while (arr[0] == ' ' || arr[0] == ',') arr.erase(0, 1);
    return result;
}

Json* Json::loadObjectsFromArray(std::string arrName, std::string arrBody) {
    Json* obj = new Json(arrName, arrBody);
    arrBody.erase(0, 1); // remove first '['
    arrBody.erase(arrBody.length() - 1, 1); // remove first '['
    int pos = 0;
    while (!arrBody.empty()) {
        obj->value[std::to_string(pos)] = loadvalueFromObject(std::to_string(pos), getObjectFromArray(arrBody));
        pos++;
    }
    return obj;
}

Json* Json::loadvalueFromObject(std::string objName, std::string objBody) {
    Json* obj = new Json(objName, objBody);
    std::string name, value;
    std::smatch match;
    while (std::regex_search(objBody, match, regex_value_in_obj)) {
        std::smatch::iterator i = match.begin();
        i++;
        name = i->str();
        i++;
        value = i->str();
        if (i->str()[0] == '{') {// is other object
            obj->value[name] = loadvalueFromObject(name, value);
        }
        else if (i->str()[0] == '[') {// is array
            obj->value[name] = loadObjectsFromArray(name, value);
        }
        else {// is simple property
            obj->value[name] = new Property(name, value);
        }
        objBody = match.suffix().str(); // extract groups finded in objBody
    }
    return obj;
}

std::string Json::getFile() {
    return file;
}

std::string Json::getPath() {
    return path;
}

Json::operator std::string() {
    return "GET STRING PROPERTY";
}

Json& Json::operator[](const char* prop) {
    return getProperty(std::string(prop));
}

Json& Json::operator[](std::string prop) {
    return getProperty(prop);
}

Json& Json::operator[](int index)
{
    return getProperty(std::to_string(index));
}

Json& Json::getProperty(std::string prop) {
    Element* e = value[prop];
    Property* p = dynamic_cast<Property*>(e);
    if (p) {

    }
    else {
        Json* j = dynamic_cast<Json*>(e);
    }
}