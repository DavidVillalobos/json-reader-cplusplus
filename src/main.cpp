/*
    File: main.cpp
    Author: David Villalobos
    Date: 2021-12-03
    Description: Main's project
*/
// Includes
#include<iostream>

#include"JsonReader.h"

void execute_test(JsonReader& file, int number, std::string path, std::string val_expected);

int main(int argc, char** argv){
	// READFILE example.json
	JsonReader file_1("example.json");
	// READFILE example2.json
	JsonReader file_2("example2.json");

	// Test example.json
	std::cout << "Test for " << file_1.getPath() << std::endl;
	// TEST #1
	execute_test(file_1, 1, "Name", "Denu");
	// TEST #2
	execute_test(file_1, 2, "Contact", "12345678");

	// Test example2.json
	std::cout << "Test for " << file_2.getPath() << std::endl;
	// TEST #1
	execute_test(file_2, 1, "firstName", "Rack");
	// TEST #2
	execute_test(file_2, 2, "address/postalCode", "394221");
	// TEST #3
	execute_test(file_2, 3, "address/street", "126"); // misspelled property (error expected)
	// TEST #4
	execute_test(file_2, 4, "phoneNumbers/1/number", "8462945527");
}

void execute_test(JsonReader& file, int number, std::string path, std::string val_expected){
	std::string result = file[path]; 
	std::cout << "Test #" << number << ((result == val_expected)? " Pass :D" : " Fail :c") << std::endl;
}

