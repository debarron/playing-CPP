// ClassSolution.cpp
// @debarron
// 03/15/2017
// Counting words in a file 

#include "Word.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void resizeArray(Word* &wordArr, int &size){
	int newSize = size * 2;
	Word *newWordArr = new Word[newSize];

	for (int i = 0; i < size; i++){
		newWordArr[i].setWord(wordArr[i].getWord());
		newWordArr[i].setCount(wordArr[i].getCount());
	}

	size = newSize;
	wordArr = newWordArr;
}

int main(){
	int ARRAY_SIZE = 100;
	string word;
	Word *words = new Word[ARRAY_SIZE];
	int lastElement = 0;

	ifstream input("input.txt");
	if(input.fail()){
		cout << "Error while reading the file\n";
		exit(1);
	}

	// Before we start, lets clean the memory
	for (int i = 0; i < ARRAY_SIZE; i++){
		words[i].setWord("");
		words[i].setCount(0);
	}

	while(!input.eof()){
		input >> word;

		// Search for the word, Can we optimize this loop?
		bool foundWord = false;
		int foundPosition = -1;
		for (int i = 0; i < ARRAY_SIZE; i++){
			if(word == words[i].getWord()){
				foundWord = true;
				foundPosition = i;
			}
		}

		// If we found the word, increase the frequency
		if(foundWord){
			words[foundPosition].increment();
		}
		else{ // If not found, lets add it if possible
			
			// Are we have space?
			if(lastElement < ARRAY_SIZE){
				words[lastElement].setWord(word);
				words[lastElement].setCount(1);
				lastElement++;
			}
			else{ // Resize the array
				// Get the new space in memory
				resizeArray(words, ARRAY_SIZE);

				// Add the word
				words[lastElement].setWord(word);
				words[lastElement].setCount(1);
				lastElement++;
			}
		}
	}

	// Lets get the output
	cout << "Words found: " << lastElement << '\n';
	cout << "Array's max size: " << ARRAY_SIZE << "\n\n\n";
	for (int i = 0; i < ARRAY_SIZE; i++){
		cout << words[i].getWord() << " -- " << words[i].getCount() << '\n';
	}

	return 0;
}