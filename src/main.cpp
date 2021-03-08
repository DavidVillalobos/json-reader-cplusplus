/*
    File: main.cpp
    Author: David Villalobos
    Date: 2021-08-03
    Description: Main's project
*/

#include<iostream>
using namespace std;

#include"Simple.h"
#include"Composite.h"

int main(int argc, char** argv){
	Composite v("person", "object");
	string name = "age";
	v.properties.insert({name, new Simple<int>(name, 21)});
	Property* f = v.properties[name];
	if(f->getType() == "int"){
		Simple<int> *c = dynamic_cast<Simple<int>*>(f);
		int val = c->getValue();
		cout << "The val is " << val << endl; 
	}
}
