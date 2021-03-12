/*
    File: Element.h
    Author: David Villalobos
    Date: 2021-12-03
    Description: Declaration of Base class to represent a property of a json
*/

#ifndef ELEMENT_H
#define ELEMENT_H

// Includes
#include<ostream>
#include<string>

class Element{
    protected:
        std::string name, value;
    public:
        Element(std::string name, std::string value);
        virtual ~Element();
        friend std::ostream& operator <<(std::ostream &o, const Element &e);
        std::string getName();
        std::string getValue();
};

#endif // !ELEMENT_H