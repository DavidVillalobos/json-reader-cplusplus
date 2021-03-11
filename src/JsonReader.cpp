/*
    File: JsonReader.cpp
    Author: David Villalobos
    Date: 2021-11-03
    Description: Implementation of class JsonReader
    to reader a file json and create a structure.
*/
#include"JsonReader.h"

JsonReader::JsonReader(string path){
    this->path = path;
    this->regex_objects_in_array = regex("(\\{[\\w0-9.]+:,\"]+\\},?)");
    this->regex_properties_in_obj = regex("\"([\\w0-9.]+)\":\"?([\\w0-9.]+)\"?,?|\"([\\w0-9.]+)\":\\[(.+)\\]");
    // Bugs when read a json file :0
    ifstream f(path);
    if(!f.good()){
        cout << "FAIL: File not load" << endl;
    }else{
        string aux;
        while (!f.eof()){
            getline(f, aux);
            file += aux;
        }
    }
    // Remove spaces tabs and endlines
    regex r("\n|\t| "); 
    file = regex_replace(file, r, ""); 
    this->object = loadPropertiesFromObject("root", file);
}

Composite* JsonReader::loadObjectsFromArray(string arrName, string arrBody){
    Composite* obj = new Composite(arrName, arrBody);
    smatch match;
    while (regex_search(arrBody, match, regex_objects_in_array)) {
        int pos = 0;
        cout << "Regex ";
        for(smatch::iterator i = match.begin(); i != match.end(); i++){
            cout <<  "arr[" << pos << "] -> "<< i->str() << "\t";
        }
        cout << endl;
        arrBody = match.suffix().str(); // extract groups finded in objBody
    }
    return obj;
}

Composite* JsonReader::loadPropertiesFromObject(string objName, string objBody){
    Composite* obj = new Composite(objName, objBody);
    string name, value;
    smatch match;
    while (regex_search(objBody, match, regex_properties_in_obj)) {
        int pos = 0;
        for(smatch::iterator i = match.begin(); i != match.end(); i++){
            if(i->str() != ""){
                if(pos == 1){ // is simple property
                    name = i->str();        
                    i++;                    
                    value = i->str();      
                    obj->prop[name] = new Property(name,value); // build Property         
                } else if (pos == 3){ // is an array or object
                    name = i->str();       
                    i++;
                    value = i->str();
                    if(regex_search(value, regex_objects_in_array)){ // is array
                        obj->prop[name] = loadObjectsFromArray(name, value);
                    }else{
                        obj->prop[name] = loadPropertiesFromObject(name, value);
                    }
                }
            }
            pos++;
        }
        objBody = match.suffix().str(); // extract groups finded in objBody
    }
    return obj; 
}

string JsonReader::getFile(){
    return file;
}

string JsonReader::operator[](string prop){
    return object->prop[prop]->getValue();
}

Element* JsonReader::operator()(string prop){
    return object->prop[prop];
}
