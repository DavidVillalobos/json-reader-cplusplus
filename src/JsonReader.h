/*
    File: JsonReader.h
    Author: David Villalobos
    Date: 2021-13-03
    Description: Declaration of class JsonReader
    to reader a file json and create a structure.
*/
#ifndef JSONREADER_H
#define JSONREADER_H

//Includes
#include <regex> 
#include<fstream>

#include"Composite.h"
#include"Property.h"


class JsonReader{
    private:
        std::string path;
        std::string file;
        std::regex regex_properties_in_obj; 
        std::regex regex_objects_in_array;
        std::regex regex_load_path_prop;
        Composite* loadObjectsFromArray(std::string arrName, std::string arrBody);
        Composite* loadPropertiesFromObject(std::string objName, std::string objBody);
    public:
        Composite* object;
        JsonReader(std::string path);
        ~JsonReader();
        std::string getFile();
        std::string getPath();
        std::string operator [](std::string path_prop);
};
#endif // !JSONREADER_H