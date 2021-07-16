/*
    File: Element.h
    Author: David Villalobos
    Date: 2021-07-15
    Description: Declaration of Base class to represent a property of a json
*/

#ifndef ELEMENT_H
#define ELEMENT_H

// Includes
#include<ostream>
#include<string>

class Element{
    protected:
        std::string name;
    public:
        Element(std::string name);
        virtual ~Element();
        std::string getName();
        std::string setName();
};

#endif // !ELEMENT_H