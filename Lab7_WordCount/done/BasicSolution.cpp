// BasicSolution.cpp
// @debarron
// 03/15/2017
// Counting words in a file and working
// with static memory

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

#define ARRAY_SIZE 100

int main(){
	string word;
	string words[ARRAY_SIZE];
	int wordsFreq[ARRAY_SIZE];
	int lastElement = 0;

	ifstream input("input.txt");
	if(input.fail()){
		cout << "Error while reading the file\n";
		exit(1);
	}

	// Before we start, lets clean the memory
	for (int i = 0; i < ARRAY_SIZE; i++){
		wordsFreq[i] = 0;
		words[i] = "";
	}

	while(!input.eof()){
		input >> word;

		// Search for the word, Can we optimize this loop?
		bool foundWord = false;
		int foundPosition = -1;
		for (int i = 0; i < ARRAY_SIZE; i++){
			if(word == words[i]){
				foundWord = true;
				foundPosition = i;
			}
		}

		// If we found the word, increase the frequency
		if(foundWord){
			wordsFreq[foundPosition]++;
		}
		else{ // If not found, lets add it if possible
			
			// Do we have space in our array?
			if(lastElement < ARRAY_SIZE){
				words[lastElement] = word;
				wordsFreq[lastElement] = 1;
				lastElement++;
			}
			else{
				cout << ">> WARNING, skipping the word: " << word << '\n';
			}
		}
	}

	// Lets get the output
	cout << "Words found: " << lastElement << '\n';
	cout << "Array's max size: " << ARRAY_SIZE << "\n\n\n";
	for (int i = 0; i < ARRAY_SIZE; i++){
		cout << words[i] << " -- " << wordsFreq[i] << '\n';
	}

	return 0;
}