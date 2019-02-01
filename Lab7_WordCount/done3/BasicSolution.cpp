// BasicSolution.cpp
// @debarron
// 03/15/2017
// Reading words in static memory

#include <string>
#include <fstream>
#include <iostream>

using namespace std;

#define ARRAY_SIZE 100

int main(){
	string words[ARRAY_SIZE];
	int wordsFreq[ARRAY_SIZE];
	int lastElement = 0;
	string word;

	ifstream intput("input.txt");
	if(intput.fail()){
		cout << "Error while opening the file\n";
		exit(1);
	}

	// Clean the memory before we start
	for (int i = 0; i < ARRAY_SIZE; i++){
		words[i] = "";
		wordsFreq[i] = 0;
	}

	while(!intput.eof()){
		intput >> word;

		bool foundIt = false;
		int wordIndex = 0;
		for (int i = 0; i < ARRAY_SIZE; i++){
			if(word == words[i]){
				foundIt = true;
				wordIndex = i;
			}
		}

		if(foundIt){
			wordsFreq[wordIndex]++;
		}
		else{
			if(lastElement < ARRAY_SIZE){
				words[lastElement] = word;
				wordsFreq[lastElement] = 1;
				lastElement++;
			}
			else{
				cout << "WARNING, NEM skipping the word " << word << '\n';
			}
		}
	}

	cout << "Words found: " << lastElement << "\n";
	cout << "Array's max size: " << ARRAY_SIZE << "\n";
	for (int i = 0; i < ARRAY_SIZE; i++){
		cout << words[i] << " - " << wordsFreq[i] << "\n";
	}

	return 0;
}








