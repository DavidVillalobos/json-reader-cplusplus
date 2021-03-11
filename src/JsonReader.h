/*
    File: JsonReader.h
    Author: David Villalobos
    Date: 2021-11-03
    Description: Declaration of class JsonReader
    to reader a file json and create a structure.
*/
#ifndef JSONREADER_H
#define JSONREADER_H
//Includes
#include <iostream> 
#include <regex> 
#include<fstream>
using namespace std; 

#include"Composite.h"
#include"Property.h"

#include<iostream>

class JsonReader{
    private:
        string path;
        string file;
        Composite* object;
        regex regex_properties_in_obj; 
        regex regex_objects_in_array;
        Composite* loadObjectsFromArray(string arrName, string arrBody);
        Composite* loadPropertiesFromObject(string objName, string objBody);
    public:
        JsonReader(string path);
        string getFile();
        string operator [](string prop);
        Element* operator ()(string prop);
};
#endif // !JSONREADER_H