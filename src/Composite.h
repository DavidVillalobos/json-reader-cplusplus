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

#include"Element.h"

class Composite : public Element{
    public:
        std::map<std::string, Element*> properties;
        Composite(std::string name, std::string value);
        friend std::ostream& operator <<(std::ostream &o, const Composite &c);
        Element* getProperty(std::string prop);
        Element* getObject(int index);
        virtual ~Composite();
};

#endif // !COMPOSITE_H