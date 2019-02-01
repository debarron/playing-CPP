// Main.cpp
#include <iostream>
#include <time.h>
#include "Guess.h"
#define PAUSE system("pause")

using namespace std;

int main(){
	Guess myGuess;
	int guess;

	while(!myGuess.getGuess()){
		cout << "Please guess a number: ";
		cin >> guess;
		myGuess.makeGuess(guess);
	}

	cout << "You guessed correctly\n";
	PAUSE;
	return 0;
}

int main1(){
	srand(time(NULL));

	int num = rand() % 10 + 1;
	bool guessCorrectly = false;
	int guess;

	while(!guessCorrectly){
		cout << "Please guess a number: ";
		cin >> guess;
		guessCorrectly = (num == guess) ? true : false;
	}

	cout << "You guessed correctly\n";
	PAUSE;
	return 0;
}