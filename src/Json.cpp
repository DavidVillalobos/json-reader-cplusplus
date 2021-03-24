/*
    File: Json.cpp
    Author: David Villalobos
    Date: 2021-24-03
    Description: Implementation of class Json
    to reader a file json and create a structure.
*/
#include"Json.h"

Json::Json(std::string path){
    this->path = path;
    this->regex_properties_in_obj = std::regex("\"([\\w0-9.]+)\":\"?([\\w0-9.]+|\\[[\\w0-9.\"{}:,]+\\]|\\{[\\w0-9.\"{}:,]+\\})\"?");
    this->regex_load_path_prop = std::regex("([\\w.'_-]+)/?");
    // Bugs when debbuger (gdb) maybe not locate a file :0
    // Read a json file  /*
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
    //file = "{\"firstName\":\"Rack\",\"lastName\":\"Jackon\",\"gender\":\"man\",\"age\":24,\"address\":{\"streetAddress\":\"126\",\"city\":\"SanJone\",\"state\":\"CA\",\"postalCode\":\"394221\"},\"phoneNumbers\":[{\"type\":\"home\",\"number\":\"7383627627\",\"example\":{\"object\":\"name\",\"value\":false}},{\"type\":\"office\",\"number\":\"8462945527\"}]}";
    // Remove spaces tabs and endlines
    std::regex r("\n|\t| "); 
    file = std::regex_replace(file, r, "");
    this->object = loadPropertiesFromObject("root", file);
}

Json::~Json(){
    delete object;
}

std::string Json::getObjectFromArray(std::string &arr){
    std::string result = "";
    char simbol;
    int cant_curly_brackets = 1;
    arr.erase(0,1); // remove first '{'
    while(true){
        simbol = arr[0];
        arr.erase(0,1);
        if(simbol == '{'){ cant_curly_brackets++; }
        else if(simbol == '}'){ cant_curly_brackets--; }
        if(cant_curly_brackets == 0){ break; }
        result += simbol;
    }
    // Remove a residue
    while(arr[0] == ' ' || arr[0] == ',') arr.erase(0,1);
    return result;
} 

Composite* Json::loadObjectsFromArray(std::string arrName, std::string arrBody){
    Composite* obj = new Composite(arrName, arrBody);
    arrBody.erase(0,1); // remove first '['
    arrBody.erase(arrBody.length()-1, 1); // remove first '['
    int pos = 0;
    while (!arrBody.empty()) {
        obj->properties[std::to_string(pos)] = loadPropertiesFromObject(std::to_string(pos), getObjectFromArray(arrBody));
        pos++;
    }
    return obj;
}

Composite* Json::loadPropertiesFromObject(std::string objName, std::string objBody){
    Composite* obj = new Composite(objName, objBody);
    std::string name, value;
    std::smatch match;
    while (std::regex_search(objBody, match, regex_properties_in_obj)) {
        std::smatch::iterator i = match.begin(); 
        i++;
        name = i->str();
        i++;        
        value = i->str();      
        if(i->str()[0] == '{'){// is other object
            obj->properties[name] = loadPropertiesFromObject(name, value);
        } else if(i->str()[0] == '['){// is array
            obj->properties[name] = loadObjectsFromArray(name, value);
        }else{// is simple property
            obj->properties[name] = new Property(name,value);
        }
        objBody = match.suffix().str(); // extract groups finded in objBody
    }
    return obj; 
}

std::string Json::getFile(){
    return file;
}

std::string Json::getPath(){
    return path;
}

std::string Json::operator[](std::string path_prop){
    std::smatch match;
    Element* e = object; 
    std::string res = "";
    std::string prop = "";
    int index;
    while (regex_search(path_prop, match, regex_load_path_prop)) {
        std::smatch::iterator i = match.begin();
        i++;
        prop = i->str();
        try{
            index = std::stoi(prop);// is array
            e = ((Composite*)e)->getObject(index); 
        }catch(...){ // is object or simple property
            e =  ((Composite*)e)->getProperty(prop);
        }
        if(e) res = e->getValue();
        else return ""; // raise exception
        path_prop = match.suffix().str();
    } 
    return res;
}
