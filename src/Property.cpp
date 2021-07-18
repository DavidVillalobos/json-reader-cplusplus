/*
    File: Property.cpp
    Author: David Villalobos
    Date: 2021-07-17
    Description: Implementation of class Property
    to represent a simple value of a json, as
    int, float, bool or string.
*/

#include"Property.h"

Property::Property(std::string name, std::string value) : Element(name) {
    this->value = value;
}

Property::Property(const Property& other) : Element(other.name) {
    this->value = other.value;
}

std::ostream& operator << (std::ostream &o,const Property &p)
{
    o << p.value;
    return o;
}

std::string Property::getValue(){
    return value;
}

Property::~Property(){ }