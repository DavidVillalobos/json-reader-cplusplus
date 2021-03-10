/*
    File: main.cpp
    Author: David Villalobos
    Date: 2021-08-03
    Description: Main's project
*/

#include<iostream>
using namespace std;

#include"Element.cpp"
#include"Property.cpp"
#include"Composite.cpp"
/*
	Example in json
	{
		"name" : "David",
		"age" : 21,
		"notes" : [
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
	root->prop["name"] = new Property("name", "David");
	root->prop["age"] = new Property("age", "21");
	cout << ((Property*)root->prop["name"])->getValue() << endl;
	/*Composite* math = new Composite("object");
	math->prop["name"] = new Property("name", "math");
	math->prop["grade"] = new Property("grade", "87");

	Composite* spanish = new Composite("object");
	spanish->prop["name"] = new Property("name", "spanish");
	spanish->prop["grade"] = new Property("grade", "70");
	
	Composite* science = new Composite("object");
	science->prop["name"] = new Property("name", "science");
	science->prop["grade"] = new Property("grade", "90");
	
	Composite* notes = new Composite("array", "notes");
	notes->prop["1"] = science;
	notes->prop["2"] = spanish;
	notes->prop["3"] = math;
	
	root->prop["notes"] = notes;	

	// How to print the grade of spanish?  --> ["notes"][1]["grade"]
	
	Composite* pull_notes = (Composite*) root->prop["notes"];
	Property *p = pull_notes->indexAt(1);
	Composite* pull_spanish = (Composite*) p;
	Property<string>* pull_name = (Property<string>*) pull_spanish->prop["name"];
	Property<int>* pull_grade = (Property<int>*) pull_spanish->prop["grade"];

	cout << "The grade of " << pull_name->getValue() << " is :" << pull_grade->getValue();
	*/
	delete root;
}
