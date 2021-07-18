/*
    File: main.cpp
    Author: David Villalobos
    Date: 2021-07-17
    Description: Main's project with test cases


    MIT License

    Copyright (c) 2021 Luis David Villalobos González

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in all
    copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
    SOFTWARE.
*/

// Includes
#include<iostream>
#include"Json.h"

//#define _CRTDBG_MAP_ALLOC
//#include <stdlib.h>
//#include <crtdbg.h>

void testFile1();
void testFile2();
void testFile3();

int main(int argc, char** argv) {
    testFile1();
    testFile2();
    testFile3();
    //_CrtDumpMemoryLeaks(); // show memory leaks
    //system("echo Memory leaks can be viewed from the console & timeout 5");
}

void testFile1() {
    try {
        Json file("example.json");
        std::string name = file["Name"];
        if (name != "Denu") {
            std::cout << "Fail No Pass " << file["Name"] << " != Denu" << std::endl;
        } else if (file["LastName"] != "Jhonson") {
            std::cout << "Fail No Pass " << file["LastName"] << " != Jhonson" << std::endl;
        } else if (file["Contact"] != 12345678) {
            std::cout << "Fail No Pass " << file["Contact"] << " != 12345678" << std::endl;
        } else if (!file["Admin"]) {
            std::cout << "Fail No Pass " << file["Admin"] << " != true" << std::endl;
        } else {
            std::cout << "All test file 1 passed :D" << std::endl;
        }
    }
    catch (std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }
}

void testFile2() {
    try {
        Json file("example2.json");
        std::string name = file["firstName"];
        if (name != "Rack") {
            std::cout << "Fail No Pass " << file["firstName"] << " != Rack" << std::endl;
        } else if (file["age"] != 24) {
            std::cout << "Fail No Pass " << file["age"] << " != 24" << std::endl;
        } else if (file["address"]["city"] != "San Jone") {
            std::cout << "Fail No Pass " << file["address"]["city"] << " != San Jone" << std::endl;
        } else if (file["phoneNumbers"][1]["number"] != "8462945527") {
            std::cout << "Fail No Pass " << file["phoneNumbers"][1]["number"] << " != 8462945527" << std::endl;
        } else {
            std::cout << "All test file 2 passed :D" << std::endl;
        }
    }
    catch (std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }
}

void testFile3() {
    try {
        Json file("example3.json");
        std::string id = file["products"][0]["id"];
        if (id != "0001") {
            std::cout << "Fail No Pass " << id << " != 0001" << std::endl;
        } else if (file["products"][0]["topping"][3]["type"] != "Powdered Sugar") {
            std::cout << "Fail No Pass " << file["products"][1]["toppings"][3]["type"] << " != Powdered Sugar" << std::endl;
        } else if (file["products"][1]["price"] != 3.55) {
            std::cout << "Fail No Pass " << file["products"][1]["price"] << " != 3.55" << std::endl;
        } else if (file["products"][2]["batters"]["batter"][1]["id"] != 1002) {
            std::cout << "Fail No Pass " << file["products"][2]["batters"]["batter"][1]["id"] << " != 1002" << std::endl;
        } else {
            std::cout << "All test file 3 passed :D" << std::endl;
        }
    }
    catch (std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }
}