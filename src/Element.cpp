/*
    File: Element.cpp
    Author: David Villalobos
    Date: 2021-12-03
    Description: Implementation of base class to represent a property of a json
*/

#include"Element.h"

Element::Element(std::string name, std::string value){
    this->name = name; 
    this->value = value; 
}

Element::~Element(){ 

}

std::string Element::getName(){
    return name;
}

std::string Element::getValue(){
    return value;
}

std::ostream& operator << (std::ostream &o,const Element &e){
    o << e.value;
    return o;
}