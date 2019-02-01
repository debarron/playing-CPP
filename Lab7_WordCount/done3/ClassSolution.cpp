// ClassSolution.cpp
// @debarron
// 03/15/2017
// Reading words in a class fashion

#include <string>
#include <fstream>
#include <iostream>
#include "Word.h"

using namespace std;

void resizeArray(Word* &w, int &size){
	int newSize = size * 2;
	Word *newArray = new Word[newSize];

	for(int i = 0; i < size; i++){
		newArray[i].setWord(w[i].getWord());
		newArray[i].setCount(w[i].getCount());
	}
	delete [] w;

	w = newArray;
	size = newSize; 
}

int main(){
	int ARRAY_SIZE = 10;
	Word *words = new Word[ARRAY_SIZE];

	int lastElement = 0;
	string word;

	ifstream intput("input.txt");
	if(intput.fail()){
		cout << "Error while opening the file\n";
		exit(1);
	}

	// Clean the memory before we start
	for (int i = 0; i < ARRAY_SIZE; i++){
		words[i].setWord("");
		words[i].setCount(0);
	}

	while(!intput.eof()){
		intput >> word;

		bool foundIt = false;
		int wordIndex = 0;
		for (int i = 0; i < ARRAY_SIZE; i++){
			if(word == words[i].getWord()){
				foundIt = true;
				wordIndex = i;
			}
		}

		if(foundIt){
			words[wordIndex].increment();
		}
		else{
			if(lastElement < ARRAY_SIZE){
				words[lastElement].setWord(word);
				words[lastElement].setCount(1);
				lastElement++;
			}
			else{
				// int newSize = ARRAY_SIZE * 2;
				// Word *newWords = new Word[newSize];

				// for (int i = 0; i < ARRAY_SIZE; i++){
				// 	newWords[i].setWord(words[i].getWord());
				// 	newWords[i].setCount(words[i].getCount());
				// }
				// delete [] words;

				// words = newWords;
				// ARRAY_SIZE = newSize;

				resizeArray(words, ARRAY_SIZE);

				words[lastElement].setWord(word);
				words[lastElement].setCount(1);
				lastElement++;
			}
		}
	}

	cout << "Words found: " << lastElement << "\n";
	cout << "Array's max size: " << ARRAY_SIZE << "\n";
	for (int i = 0; i < lastElement; i++){
		cout << words[i].getWord() << " - " << words[i].getCount() << "\n";
	}
	
	return 0;
}








