/*
    File: Composite.h
    Author: David Villalobos
    Date: 2021-12-03
    Description: Declaration of class Composite
    to represent a object or an array.
*/

#ifndef COMPOSITE_H
#define COMPOSITE_H

// Includes
#include <map>
#include <regex> 
#include<fstream>

#include"Property.h"

class Json : public Element{
    private:
        std::map<std::string, Element*> value;
        std::string path;
        std::string file;
        Json* loadObjectsFromArray(std::string arrName, std::string arrBody);
        Json* loadPropertiesFromObject(std::string objName, std::string objBody);
        std::string getObjectFromArray(std::string& arr);
        Json& getProperty(std::string prop);
    public:
        Json(std::string path);
        Json(std::string name, std::string value);
        friend std::ostream& operator <<(std::ostream &o, const Json &c)

        ~Json();
        std::string getFile();
        std::string getPath();
        operator std::string();
        Json& operator[](const char* prop);
        Json& operator[](std::string prop);
        Json& operator[](int index);
};

#endif // !COMPOSITE_H