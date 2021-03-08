/*
    File: Composite.h
    Author: David Villalobos
    Date: 2021-08-03
    Description: Declaration of class Composite
    to represent a object or an array.
*/

#ifndef COMPOSITE_H
#define COMPOSITE_H

// Includes
#include <map>
using std::map;

#include"Property.h"

class Composite : public Property{
    public:
        map<string, Property*> prop;
        Composite(string type, string name = "");
        Property* indexAt(int position);
        virtual ~Composite();
};

#endif // !COMPOSITE_H