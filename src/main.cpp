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
/*
	Example in json
	{
		"name" : "David",
		"age" : 21,
		"notes" = [
			{
				"subject" : "math", 
				"grade" : 87
			}, {
				"subject" : "spanish", 
				"grade" : 70
			}, {
				"subject" : "science", 
				"grade" : 90
			}
		]
	}
*/

int main(int argc, char** argv){
	Composite* root = new Composite("object");
	root->prop["name"] = new Simple<string>("name", "David");
	root->prop["age"] = new Simple<int>("age", 21);
	
	Composite* math = new Composite("object");
	math->prop["name"] = new Simple<string>("name", "math");
	math->prop["grade"] = new Simple<int>("grade", 87);

	Composite* spanish = new Composite("object");
	spanish->prop["name"] = new Simple<string>("name", "spanish");
	spanish->prop["grade"] = new Simple<int>("grade", 70);
	
	Composite* science = new Composite("object");
	science->prop["name"] = new Simple<string>("name", "science");
	science->prop["grade"] = new Simple<int>("grade", 90);
	
	Composite* notes = new Composite("array", "notes");
	notes->prop["1"] = science;
	notes->prop["2"] = spanish;
	notes->prop["3"] = math;
	
	root->prop["notes"] = notes;	

	// How to print the grade of spanish?  --> ["notes"][1]["grade"]
	
	Composite* pull_notes = (Composite*) root->prop["notes"];
	Property *p = pull_notes->indexAt(1);
	Composite* pull_spanish = (Composite*) p;
	Simple<string>* pull_name = (Simple<string>*) pull_spanish->prop["name"];
	Simple<int>* pull_grade = (Simple<int>*) pull_spanish->prop["grade"];

	cout << "The grade of " << pull_name->getValue() << " is :" << pull_grade->getValue();

	delete root;
}
