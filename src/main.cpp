/*
    File: main.cpp
    Author: David Villalobos
    Date: 2021-25-03
    Description: Main's project with test cases
*/
// Includes
#include<iostream>

#include"Json.h"

void execute_test(Json& file, int number, std::string path, std::string val_expected);

int main(int argc, char** argv){
	// READFILE example.json
	Json file_1("example.json");
	std::cout << file_1["LastName"];
	// READFILE example2.json
	//Json file_2("example2.json");
	//int number_test = 1;
	// Test example.json
	//std::cout << "Test for " << file_1.getPath() << std::endl;
	// TEST #1
	//execute_test(file_1, number_test++, "Name", "Denu");
	// TEST #2
	//execute_test(file_1, number_test++, "Contact", "12345678");
	//number_test = 1;
	// Test example2.json
	//std::cout << "Test for " << file_2.getPath() << std::endl;
	// TEST #1
	//execute_test(file_2, number_test++, "firstName", "Rack");
	// TEST #2
	//execute_test(file_2, number_test++, "address/city", "San Jone");
	// TEST #3
	//execute_test(file_2, number_test++, "address/postalCode", "394221");
	// TEST #4
	//execute_test(file_2, number_test++, "address/streetAddress", "126");
	// TEST #5
	//execute_test(file_2, number_test++, "firstName", "8462945527");
	std::cin.get();
}

void execute_test(Json& file, int number, std::string path, std::string val_expected){
	std::string result = file[path];
	std::cout << "Test #" << number << " -> " << result << std::endl;
	//std::cout << "Test #" << number << " -> " << ((result == val_expected)? " Pass :D" : " Fail :c") << '\n';
}

