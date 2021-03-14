#include<iostream>
using namespace std;

#include"JsonReader.h" // include this file

int main(int argc, char** argv){
    // build a Object Json
	Json file("file.json"); // path to json file
    // Get properties like -> file["path_to_property"]
    cout << "The name is " << file["firstName"] << ' ' << file["lastName"] << endl;
    cout << "The city is " << file["address/city"] << endl;
    cout << "The phone office is " << file["phoneNumbers/1/number"] << endl;
}