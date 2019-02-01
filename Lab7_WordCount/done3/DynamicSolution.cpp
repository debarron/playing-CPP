// DynamicSolution.cpp
// @debarron
// 03/15/2017
// Reading words in dynamic memory

#include <string>
#include <fstream>
#include <iostream>

using namespace std;

// #define ARRAY_SIZE 100

int main(){
	int ARRAY_SIZE = 10;
	
	string *words = new string[ARRAY_SIZE];
	int *wordsFreq = new int[ARRAY_SIZE];


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
				int newSize = ARRAY_SIZE * 2;
				string *newWords = new string[newSize];
				int *newWFreq = new int[newSize];

				for (int i = 0; i < ARRAY_SIZE; i++){
					newWords[i] = words[i];
					newWFreq[i] = wordsFreq[i];
				}
				delete [] words;
				delete [] wordsFreq;

				words = newWords;
				wordsFreq = newWFreq;
				ARRAY_SIZE = newSize;

				words[lastElement] = word;
				wordsFreq[lastElement] = 1;
				lastElement++;
				// cout << "WARNING, NEM skipping the word " << word << '\n';
			}
		}
	}

	cout << "Words found: " << lastElement << "\n";
	cout << "Array's max size: " << ARRAY_SIZE << "\n";
	for (int i = 0; i < lastElement; i++){
		cout << words[i] << " - " << wordsFreq[i] << "\n";
	}
	
	return 0;
}








