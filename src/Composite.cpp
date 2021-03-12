/*
    File: Composite.cpp
    Author: David Villalobos
    Date: 2021-12-03
    Description: Implementation of class Composite
    to represent a object or an array.
*/
#include"Composite.h"

Composite::Composite(std::string name, std::string value) : Element(name, value){

}

Element* Composite::getObject(int index){
	if(0 <= index && (unsigned int) index < properties.size()) {
        for (auto x : properties){
            if(x.first == std::to_string(index)){
                return x.second;
            }
        }
    }
    // Index out of boundsx
    return nullptr;
}

Element* Composite::getProperty(std::string prop){
    return properties[prop];
}

std::ostream& operator << (std::ostream &o,const Composite &c)
{
    o << c.value;
    return o;
}

Composite::~Composite(){
    for (auto x : properties){
        delete x.second; // free memory
    }
}