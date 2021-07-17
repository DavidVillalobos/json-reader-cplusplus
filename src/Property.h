/*
    File: Property.h
    Author: David Villalobos
    Date: 2021-07-17
    Description: Declaration of class Property
    to represent a simple value of a json, as
    int, float, bool or string.
*/

#ifndef PROPERTY_H
#define PROPERTY_H
// Includes
#include"Element.h"

class Property : public Element{
    private:
        std::string value;
    public:
        Property(std::string name, std::string value);
        friend std::ostream& operator <<(std::ostream &o, const Property &p);
        std::string getValue();
        virtual ~Property();
};

#endif // !PROPERTY_H