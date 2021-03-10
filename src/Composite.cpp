/*
    File: Composite.cpp
    Author: David Villalobos
    Date: 2021-09-03
    Description: Implementation of class Composite
    to represent a object or an array.
*/
#include"Composite.h"

Composite::Composite(string name) : Element(name){

}

Element* Composite::operator[](int position){
	if(0 <= position && (unsigned int) position < prop.size()) {
        int pos = 0;
        for (auto x : prop){
            if(pos == position){
                return x.second;
            }
            pos++;
        }
    }
    // Index out of bounds
    return nullptr;
}

Composite::~Composite(){
    for (auto x : prop){
        delete x.second; // free memory
    }
}