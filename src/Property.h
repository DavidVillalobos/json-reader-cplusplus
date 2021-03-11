/*
    File: Property.h
    Author: David Villalobos
    Date: 2021-11-03
    Description: Declaration of class Property
    to represent a simple value of a json, as
    int, float, bool or string.
*/

#ifndef PROPERTY_H
#define PROPERTY_H
// Includes
#include<ostream>
using std::ostream;
#include"Element.h"

class Property : public Element{
    public:
        Property(string name, string value);
        string getValue();
        friend ostream& operator <<(ostream &o, const Property &p);
        virtual ~Property();
};

#endif // !PROPERTY_H