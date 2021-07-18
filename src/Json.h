/*
    File: Json.h
    Author: David Villalobos
    Date: 2021-07-17
    Description: Declaration of class Composite
    to represent a object or an array.
*/

#ifndef JSON_H
#define JSON_H

// Includes
#include <map>
#include <regex> 
#include<fstream>

#include"Property.h"

class Json : public Element{
    private:
        std::map<std::string, Element*> value;
        std::string path;
        Json getProperty(std::string prop);
        static std::string sliceText(std::string& text, char begin, char end);
    public:
        Json(std::string path = "");
        Json(const Json& other);
        Json& operator=(const Json& other);
        ~Json();
        void ObjectFromString(Json* temp, std::string object);
        void ArrayFromString(Json * temp, std::string array);
        std::string getPath();

        friend std::ostream& operator <<(std::ostream& o, const Json& c);
        
        operator std::string();
        operator int();
        operator float();
        operator bool();

        Json operator[](const char* prop);
        Json operator[](std::string prop);
        Json operator[](int index);

        bool operator==(const char* value);
        bool operator==(const std::string value);
        bool operator==(const int value);
        bool operator==(const float value);
        bool operator==(const bool value);
        
        bool operator!=(const char* value);
        bool operator!=(const std::string value);
        bool operator!=(const int value);
        bool operator!=(const float value);
        bool operator!=(const bool value);

};

#endif // !JSON