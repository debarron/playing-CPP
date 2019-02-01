// Animal.h
// debarron
// Description of Animal.cpp
#include <string>
using namespace std;

#ifndef ANIMAL_H
#define ANIMAL_H

class Animal{
private:
	double age;
	string name;


public:
	Animal();
	string getName();
	double getAge();
	void setName(string _name);
	void setAge(double _age);

};

#endif