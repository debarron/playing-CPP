// Animal.cpp
// debarron
// 02/15/2017
// Testing of OOPs
#include <string>
#include "Animal.h"

using namespace std;

Animal::Animal(){
	age = 0;
	name = "No Name";
}

string Animal::getName(){
	return name;
}

double Animal::getAge(){
	return age;
}

void Animal::setName(string _name){
	name = _name;
}
void Animal::setAge(double _age){
	age = _age;
}


