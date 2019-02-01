// main.cpp
// debarron
// Test of Animal class

#include <string>
#include <iostream>
#include "Animal.h"

using namespace std;

int main(){
	cout << "Animal test\n";

	Animal pet;

	cout << "New pet, details:\n";
	cout << "\t Name: " << pet.getName() << "\n";
	cout << "\t Age: " << pet.getAge() << "\n";

	cout << "Let's change the pet's data";
	pet.setAge(3);
	pet.setName("Jax");


	cout << "New pet, details:\n";
	cout << "\t Name: " << pet.getName() << "\n";
	cout << "\t Age: " << pet.getAge() << "\n";


	return 0;
}