/*
    File: main.cpp
    Author: David Villalobos
    Date: 2021-09-03
    Description: Main's project
*/

#include<iostream>
using namespace std;

#include"JsonReader.h"

int main(int argc, char** argv){
	JsonReader a("example.json");
	a.loadObject();
	Property* result = (Property*) a["name"]; 
	if(result->getValue() == "David"){
		cout << "Pass Test #1"; 
	}else{
		cout << "Fail Test #1"; 
	}
}
