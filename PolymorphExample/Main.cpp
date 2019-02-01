// Main.cpp

#include <iostream>
#include <fstream>
#include <string>
#include "Test.h"
using namespace std;

bool getData(istream& _stream){
	int age;
	string name;
	bool result = true;

	cout << "Read data\n";
	
	cout << "Age is: ";
	_stream >> age;
	
	cout << "Name is: ";
	_stream >> name;

	cout << "Hello " << name << " you're " << age << " yo\n";

	return result;
}

int main(){
	int a = 10;
	int b = 20;

	string g = "The value is " + to_string(a) + " and " + to_string(b);

	cout << g << "\n";

	Test myTest[10];
	Test *myTest2 = new Test[10];

	for(int i = 0; i < 10; i++){
		myTest2[i] = Test(i, "Binh");
		myTest[i] = Test(i*2, "Daniel");

		Test testOverload(i*3, "201");
		Test testDefault;

		cout << "Test1: " << myTest[i].getData() << "\n";
		cout << "Test2: " << myTest2[i].getData() << "\n";
		cout << "Test3: " << testOverload.getData() << "\n";
		cout << "Test3: " << testDefault.getData() << "\n";
	}

	// // Data from the keyboard
	// cout << "Reading from the keyboard\n";
	// getData(cin);

	// // Data from a file
	// cout << "\n\n------------------\n";
	// cout << "Reading from the file\n";
	// ifstream input("data.txt");
	// getData(input);

	return 0;
}