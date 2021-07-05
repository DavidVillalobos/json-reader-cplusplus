/*
    File: Json.h
    Author: David Villalobos
    Date: 2021-24-03
    Description: Declaration of class Json
    to reader a file json and create a structure.
*/
#ifndef JSON_H
#define JSON_H

//Includes
#include <regex> 
#include<fstream>

#include"Composite.h"
#include"Property.h"


class Json{
    private:
        std::string path;
        std::string file;
        std::regex regex_properties_in_obj; 
        std::regex regex_load_path_prop;
        Composite* loadObjectsFromArray(std::string arrName, std::string arrBody);
        Composite* loadPropertiesFromObject(std::string objName, std::string objBody);
        std::string getObjectFromArray(std::string &arr);
        Composite* object;
    public:
        Json(std::string path);
        ~Json();
        std::string getFile();
        std::string getPath();
        std::string operator [](std::string path_prop);
        std::string get(std::string path_prop, int &prop);
        std::string get(std::string path_prop, float &prop);
        std::string get(std::string path_prop, bool &prop);
        std::string get(std::string path_prop, std::string &prop);
};
#endif // !JSON_H