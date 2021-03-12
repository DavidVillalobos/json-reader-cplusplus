/*
    File: JsonReader.cpp
    Author: David Villalobos
    Date: 2021-12-03
    Description: Implementation of class JsonReader
    to reader a file json and create a structure.
*/
#include"JsonReader.h"

JsonReader::JsonReader(std::string path){
    this->path = path;
    this->regex_objects_in_array = std::regex("\\{[\\w:\".,]+,?\\}");
    this->regex_properties_in_obj = std::regex("\"([\\w0-9.]+)\":\"?([\\w0-9.]+)\"?,?|\"([\\w0-9.]+)\":\\[(.+)\\]|\"([\\w0-9.]+)\":\\{(.+)\\}");
    this->regex_load_path_prop = std::regex("([\\w.'_-]+)/?");
    // Bugs when debbuger (gdb) maybe not locate a file :0
    // Read a json file 
    std::ifstream f(path);
    if(f.good()){
        std::string aux;
        while (!f.eof()){
            getline(f, aux);
            file += aux;
        }
    }/*else{
        throw "FAIL: File not found or not load in path" + path;
    }// */
    // Remove spaces tabs and endlines
    std::regex r("\n|\t| "); 
    file = std::regex_replace(file, r, ""); // */
    // file = "{\"firstName\":\"Rack\",\"lastName\":\"Jackon\",\"gender\":\"man\",\"age\":24,\"address\":{\"streetAddress\":\"126\",\"city\":\"SanJone\",\"state\":\"CA\",\"postalCode\":\"394221\"},\"phoneNumbers\":[{\"type\":\"home\",\"number\":\"7383627627\"},{\"type\":\"office\",\"number\":\"8462945527\"}]}";
    this->object = loadPropertiesFromObject("root", file);
}

JsonReader::~JsonReader(){
    delete object;
}

Composite* JsonReader::loadObjectsFromArray(std::string arrName, std::string arrBody){
    Composite* obj = new Composite(arrName, arrBody);
    std::smatch match;
    int pos = 0;
    while (std::regex_search(arrBody, match, regex_objects_in_array)) {
        for(std::smatch::iterator i = match.begin(); i != match.end(); i++){
            obj->properties[std::to_string(pos)] = loadPropertiesFromObject(std::to_string(pos), i->str());
            pos++;
        }
        arrBody = match.suffix().str(); // extract groups finded in objBody
    }
    return obj;
}
#include<iostream>

Composite* JsonReader::loadPropertiesFromObject(std::string objName, std::string objBody){
    Composite* obj = new Composite(objName, objBody);
    std::string name, value;
    std::smatch match;
    while (std::regex_search(objBody, match, regex_properties_in_obj)) {
        int pos = 0;
        for(std::smatch::iterator i = match.begin(); i != match.end(); i++){
            if(i->str() != ""){
                if(pos == 1){ // is simple property
                    name = i->str();        
                    i++;
                    value = i->str();      
                    obj->properties[name] = new Property(name,value); // build Property
                    break;      
                } else if (pos == 3){ // is an array of objects
                    name = i->str();       
                    i++;
                    value = i->str();
                    if(regex_search(value, regex_objects_in_array)){ // is array
                        obj->properties[name] = loadObjectsFromArray(name, value);
                    }
                    break;
                } else if(pos == 5){ // is other object
                    name = i->str();       
                    i++;
                    value = i->str();
                    if(regex_search(value, regex_properties_in_obj)){ // is object
                        obj->properties[name] = loadPropertiesFromObject(name, value);
                    }
                    break;
                }
            }
            pos++;
        }
        objBody = match.suffix().str(); // extract groups finded in objBody
    }
    return obj; 
}

std::string JsonReader::getFile(){
    return file;
}

std::string JsonReader::getPath(){
    return path;
}

std::string JsonReader::operator[](std::string path_prop){
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
            index = std::stoi(prop);
            e = ((Composite*)e)->getObject(index);
        }catch(...){
            e =  ((Composite*)e)->getProperty(i->str());
        }
        if(e){
            res = e->getValue();
        }else{
            return ""; // raise exception
        }
        path_prop = match.suffix().str();
    } 
    return res;
}
