/*
    File: Composite.cpp
    Author: David Villalobos
    Date: 2021-08-03
    Description: Implementation of class Composite
    to represent a object or an array.
*/
#include"Composite.h"

Composite::Composite(string type, string name) : Property(name, type){

}

Property* Composite::indexAt(int position){
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