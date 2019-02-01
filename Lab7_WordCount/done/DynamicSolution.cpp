// DynamicSolution.cpp
// @debarron
// 03/15/2017
// Counting words in a file and working
// with static memory

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void resizeArrays(string* &strArr, int* &intArr, int &size){
	int newSize = size * 2;
	string *newStrArr = new string[newSize];
	int *newIntArr = new int[newSize];

	for (int i = 0; i < size; i++){
		newStrArr[i] = strArr[i];
		newIntArr[i] = intArr[i];
	}

	size = newSize;
	strArr = newStrArr;
	intArr = newIntArr;
}

int main(){
	int ARRAY_SIZE = 100;
	string word;
	string *words = new string[ARRAY_SIZE];
	int *wordsFreq = new int[ARRAY_SIZE];
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
			
			// Are we have space?
			if(lastElement < ARRAY_SIZE){
				words[lastElement] = word;
				wordsFreq[lastElement] = 1;
				lastElement++;
			}
			else{ // Resize the array
				// Get the new space in memory
				resizeArrays(words, wordsFreq, ARRAY_SIZE);

				// int newSize = ARRAY_SIZE * 2;
				// int *newWordFreq = new int[newSize];
				// string *newWords = new string[newSize];

				// // Copy the content to the new space
				// for (int i = 0; i < ARRAY_SIZE; i++){
				// 	newWords[i] = words[i];
				// 	newWordFreq[i] = wordsFreq[i];
				// }
				// ARRAY_SIZE = newSize;

				// // Give the reference back to the pointer
				// words = newWords;
				// wordsFreq = newWordFreq;

				// Add the word
				words[lastElement] = word;
				wordsFreq[lastElement] = 1;
				lastElement++;
			}

			// STATIC MEMORU EXAMPLE
			// Do we have space in our array?
			// if(lastElement < ARRAY_SIZE){
			// 	words[lastElement] = word;
			// 	wordsFreq[lastElement] = 1;
			// 	lastElement++;
			// }
			// else{
			// 	cout << ">> WARNING, skipping the word: " << word << '\n';
			// }
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