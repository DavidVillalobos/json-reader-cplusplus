/*
    File: Element.h
    Author: David Villalobos
    Date: 2021-11-03
    Description: Declaration of Base class to represent a property of a json
*/

#ifndef ELEMENT_H
#define ELEMENT_H

// Includes
#include<ostream>
using std::ostream;

#include<string>
using std::string;

class Element{
    protected:
        string name, value;
    public:
        Element(string name, string value);
        virtual ~Element();
        friend ostream& operator <<(ostream &o, const Element &e);
        //operator string() const { return value; }
        string getName();
        string getValue();
};

#endif // !ELEMENT_H