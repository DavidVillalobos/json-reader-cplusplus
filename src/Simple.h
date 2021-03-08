/*
    File: Simple.h
    Author: David Villalobos
    Date: 2021-08-03
    Description: Declaration of template class Simple
    to represent a simple template value of a json, as
    int, float, double, bool or string.
*/

#ifndef SIMPLE_H
#define SIMPLE_H

// Includes
#include"Property.h"

template<class T>
class Simple : public Property{
    protected:
        T value;
    public:
        Simple(string name, T value);
        T getValue();
        virtual ~Simple();
};
#include<iostream>

template<class T>
Simple<T>::Simple(string name, T value) : Property(name){
    this->value = value;
    if(typeid(T) == typeid(int)){
        this->type = "int";
    } else if(typeid(T) == typeid(float)){
        this->type = "float";
    } else if(typeid(T) == typeid(double)){
        this->type = "double";
    } else if(typeid(T) == typeid(bool)){
        this->type = "bool";
    } else if(typeid(T) == typeid(string)){
        this->type = "string";
    }
}

template<class T>
T Simple<T>::getValue(){
    return value;
}

template<class T>
Simple<T>::~Simple(){ }

#endif // !SIMPLE_H