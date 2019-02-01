// Guess.cpp
#include "Guess.h"
#include <time.h>
#include <iostream>

using namespace std;

Guess::Guess(){
	srand(time(NULL));
	number = rand() % 10 + 1;
	guessCorrectly = false;
}
bool Guess::getGuess(){
	return guessCorrectly;
}
bool Guess::makeGuess(int _guess){
	if(number == _guess){
		guessCorrectly = true;
	}
	return guessCorrectly;
}
void Guess::setNumer(int _number){
	number = _number;
}
