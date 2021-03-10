/*
    File: Element.h
    Author: David Villalobos
    Date: 2021-09-03
    Description: Declaration of Base class to represent a property of a json
*/

#ifndef ELEMENT_H
#define ELEMENT_H

// Includes
#include<string>
using std::string;

class Element{
    private:
        string name;
    public:
        Element(string name);
        virtual ~Element();
        string getName();
};

#endif // !ELEMENT_H