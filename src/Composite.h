/*
    File: Composite.h
    Author: David Villalobos
    Date: 2021-09-03
    Description: Declaration of class Composite
    to represent a object or an array.
*/

#ifndef COMPOSITE_H
#define COMPOSITE_H

// Includes
#include <map>
using std::map;

#include"Element.h"

class Composite : public Element{
    public:
        map<string, Element*> prop;
        Composite(string name);
        virtual ~Composite();
        Element* operator [](int position);
};

#endif // !COMPOSITE_H