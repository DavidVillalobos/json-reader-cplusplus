/*
    File: Json.h
    Author: David Villalobos
    Date: 2021-08-03
    Description: Declaration of class Composite
    to represent a object or an array.
*/

#ifndef COMPOSITE_H
#define COMPOSITE_H

// Includes
#include <unordered_map>
using std::unordered_map;

#include"Property.h"

class Composite : public Property{
    public:
        unordered_map<string, Property*> properties;
        Composite(string name, string type);
        Property* indexAt(int position);
        virtual ~Composite();
};

#endif // !COMPOSITE_H