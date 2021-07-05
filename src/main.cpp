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
	// READFILE example2.json
	Json file_2("example2.json");

	int number_test = 1;
	
	// Test example.json
	
	std::cout << "Test for " << file_1.getPath() << std::endl;
	// TEST #1
	execute_test(file_1, number_test++, "Name", "Denu");
	// TEST #2
	execute_test(file_1, number_test++, "Contact", "12345678");
	
	// Test example2.json
	number_test = 1;
	std::cout << "Test for " << file_2.getPath() << std::endl;
	// TEST #1
	execute_test(file_2, number_test++, "firstName", "Rack");
	// TEST #2
	execute_test(file_2, number_test++, "address/city", "San Jone");
	// TEST #3
	execute_test(file_2, number_test++, "address/postalCode", "394221");
	// TEST #4
	execute_test(file_2, number_test++, "address/streetAddress", "126");
	// TEST #5
	execute_test(file_2, number_test++, "phoneNumbers/1/number", "8462945527");
	

	// Test example3.json
	// READFILE example3.json
	Json file_3("example3.json");
	number_test = 1;
	std::cout << "Test for " << file_3.getPath() << std::endl;
	// TEST #1
	int int_answer, int_expected = 30;
	file_3.get("products/0/stock", int_answer);
	std::cout << "Test #" << number_test++ << " -> " << ((int_answer == int_expected)? " Pass :D" : " Fail :c") << '\n';
	// TEST #2
	bool bool_answer, bool_expected = false;
	file_3.get("products/1/discount", bool_answer);
	std::cout << "Test #" << number_test++ << " -> " << ((bool_answer == bool_expected)? " Pass :D" : " Fail :c") << '\n';
	// TEST #3
	float float_answer, float_expected = 3.55;
	file_3.get("products/2/price", float_answer);
	std::cout << "Test #" << number_test++ << " -> " << ((float_answer == float_expected)? " Pass :D" : " Fail :c") << '\n';
	// TEST #4
	std::string string_answer, string_expected = "Chocolate";
	file_3.get("products/2/batters/batter/1/type", string_answer);
	std::cout << "Test #" << number_test++ << " -> " << ((string_answer == string_expected)? " Pass :D" : " Fail :c") << '\n';
}

void execute_test(Json& file, int number, std::string path, std::string val_expected){ 
	std::cout << "Test #" << number << " -> " << ((file[path] == val_expected)? " Pass :D" : " Fail :c") << '\n';
}

