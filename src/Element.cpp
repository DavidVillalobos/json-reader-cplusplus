/*
    File: Element.cpp
    Author: David Villalobos
    Date: 2021-09-03
    Description: Implementation of base class to represent a property of a json
*/

#include"Element.h"

Element::Element(string name){
    this->name = name; 
}

Element::~Element(){ 

}

string Element::getName(){
    return name;
}
