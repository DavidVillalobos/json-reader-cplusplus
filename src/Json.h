/*
    File: Composite.h
    Author: David Villalobos
    Date: 2021-07-17
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
        Json* getProperty(std::string prop);
    public:
        Json(std::string path = "");
        static Json ObjectFromString(std::string object);
        static Json ArrayFromString(std::string array);
        ~Json();
        
        std::string getPath();

        friend std::ostream& operator <<(std::ostream& o, const Json& c);
        operator std::string();
        Json& operator[](const char* prop);
        Json& operator[](std::string prop);
        Json& operator[](int index);
};

#endif // !COMPOSITE_H