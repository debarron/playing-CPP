// main.cpp
// Daniel Lopez
// 02/03/2017
// Basic use of operators

// Define a class

// Create an operator for the class

// Test it

#include <iostream>

using namespace std;

class ClassTest{
public:
	void setNumber(int num){
		myNumber = num;
	}
	int getNumber(){
		return myNumber;
	}

	ClassTest operator+(ClassTest& comp){
		ClassTest newObject;
		newObject.setNumber(this->getNumber() + comp.getNumber());

		return newObject;
	}


private:
	int myNumber;
};

int main(){
	cout << "## Operator Example \n";
	ClassTest a, b, c;

	a.setNumber(30);
	b.setNumber(10);

	c = a + b;

	cout << "Number is: " << c.getNumber() << "\n";
}