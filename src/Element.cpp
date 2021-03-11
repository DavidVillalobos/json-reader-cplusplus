/*
    File: Element.cpp
    Author: David Villalobos
    Date: 2021-11-03
    Description: Implementation of base class to represent a property of a json
*/

#include"Element.h"

Element::Element(string name, string value){
    this->name = name; 
    this->value = value; 
}

Element::~Element(){ 

}

string Element::getName(){
    return name;
}

string Element::getValue(){
    return value;
}

ostream& operator << (ostream &o,const Element &e){
    o << e.value;
    return o;
}

