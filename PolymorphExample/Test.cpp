// Test.cpp
#include "Test.h"

using namespace std;
Test::Test(){
	age = 0;
	name = "Doe";
}

Test::Test(int _age, string _name){
	age = _age;
	name = _name;
}

string Test::getData(){
	return "Name is " + name + ", age is " + to_string(age);
}