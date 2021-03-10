/*
    File: JsonReader.h
    Author: David Villalobos
    Date: 2021-08-03
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

class JsonReader{
    private:
        string path;
        string file;
        Composite* object;
    public:
        JsonReader(string path);
        void loadObject();
        string getFile();
        Element* operator [](string prop);
};
#endif // !JSONREADER_H