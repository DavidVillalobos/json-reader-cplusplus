/*
    File: Composite.cpp
    Author: David Villalobos
    Date: 2021-08-03
    Description: Implementation of class Composite
    to represent a object or an array.
*/
#include"Composite.h"

Composite::Composite(string name, string type) : Property(name, type){

}
#include<iostream>
using namespace std;

Property* Composite::indexAt(int position){
    if(0 <= position && properties.size() < (unsigned int) position) {
        int pos = 0;
        for (auto x : properties){
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
    for (auto x : properties){
        delete x.second; // free memory
    }
}