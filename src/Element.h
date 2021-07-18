/*
    File: Element.h
    Author: David Villalobos
    Date: 2021-07-17
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
};

#endif // !ELEMENT_H