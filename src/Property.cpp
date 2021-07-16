/*
    File: Property.cpp
    Author: David Villalobos
    Date: 2021-07-15
    Description: Implementation of class Property
    to represent a simple value of a json, as
    int, float, bool or string.
*/

#include"Property.h"

Property::Property(std::string name, std::string value) : Element(name){
    this->value = value;
}

std::ostream& operator << (std::ostream &o,const Property &p)
{
    o << p.value;
    return o;
}

Property::~Property(){
    
}