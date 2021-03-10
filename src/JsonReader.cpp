/*
    File: JsonReader.cpp
    Author: David Villalobos
    Date: 2021-08-03
    Description: Implementation of class JsonReader
    to reader a file json and create a structure.
*/
#include"JsonReader.h"

JsonReader::JsonReader(string path){
    this->path = path;
    object = new Composite("root");
    // Bugs when
    // Read a file
    /*
    ifstream f(path, std::ifstream::binary);
    if(!f.good())
        throw "Not found or load file " + path;
    string aux;
    while (!f.eof()){
        getline(f, aux);
        file += aux;
    }
    // Remove spaces tabs and endlines
    regex r("\n|\t| "); 
    file = regex_replace(file, r, ""); 
    */
   file = "{\"name\":\"David\",\"age\":13,\"height\":1.64,\"notes\":[{\"name\":\"spanish\",\"grade\":1.23},{\"name\":\"math\",\"grade\":3.23}]}";
}

void JsonReader::loadObject(){
    smatch m;
    regex b("\"(\\w+)\":\"?([\\w.]+)\"?,?|\"(\\w+)\":\\[(.+)\\]");
    string obj = file;
    string name, value;
    while (std::regex_search (obj,m,b)) {
        int pos = 0;
        for(smatch::iterator i = m.begin(); i != m.end(); i++){
            if(i->str() != ""){
                switch (pos){
                    case 1: {
                        name = i->str();       
                        i++;
                        value = i->str();
                        object->prop[name] = new Property(name,value);         
                        break;
                    }
                    case 3: {
                        name = i->str();       
                        i++;
                        value = i->str();
                        object->prop[name] = new Property(name,value);  
                        break;
                    }
                    default: break;
                }
            }
            pos++;
        }
        obj = m.suffix().str(); // extract group
    }
}

string JsonReader::getFile(){
    return file;
}

Element* JsonReader::operator[](string prop){
    return object->prop[prop];
}
