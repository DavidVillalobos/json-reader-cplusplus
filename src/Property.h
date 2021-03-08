/*
    File: Property.h
    Author: David Villalobos
    Date: 2021-08-03
    Description: Base class to represent a property of a json
*/

#ifndef PROPERTY_H
#define PROPERTY_H

// Includes
#include<string>
using std::string;

class Property{
    protected:
        string name;   
        string type;
    public:
        Property(string name, string type = ""){
            this->name = name; 
        }
        string getName(){
            return name;
        }
        string getType(){
            return type;
        }
        virtual ~Property(){ }
};

#endif // !PROPERTY_H