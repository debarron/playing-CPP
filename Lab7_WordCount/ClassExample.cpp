// ClassExample.cpp
// debarron
// 03/17/2017
// Simple program to do word count

/*
Take a document
Count all the different words in the document
Static memory
*/

#include <string>
#include <fstream>
#include <iostream>
#include "Word.h"

using namespace std;

int resizeArray(Word* &oldArray, int oldSize){
  int newSize = oldSize * 2;

  Word *newWords = new Word[newSize];
  for(int i = 0; i < oldSize; i++){
    newWords[i].setWord(oldArray[i].getWord());
    newWords[i].setCount(oldArray[i].getCount());
  }

  delete [] oldArray;

  oldSize = newSize;
  oldArray = newWords;

  return oldSize;
}



int main(){
  int ARRAY_SIZE  = 100;
  // string *words = new string[ARRAY_SIZE];
  // int *wordCount = new int[ARRAY_SIZE];

  Word *words = new Word[ARRAY_SIZE];

  int lastElement = 0;

  string word;
  ifstream input("input.txt");
  ofstream output("myOutput.txt");

  // Clean the memory
  for(int i = 0; i < ARRAY_SIZE; i++){
    words[i].setWord("");
    words[i].setCount(0);
  }

  if(input.fail()){
    output << "Error while opening the file\n";
    exit(1);
  }

  while(!input.eof()){
    input >> word;

    // Search for the word in the array of known words
    bool found = false;
    int foundIndex = 0;
    for(int i = 0; i < lastElement; i++){
      if(word == words[i].getWord()){
        found = true;
        foundIndex = i;
      }
    }

    if(found){ // Of found, increment the counter
      words[foundIndex].increment();
    }
    else{ // Add the word to the list
      if(lastElement >= ARRAY_SIZE){
        ARRAY_SIZE = resizeArray(words, ARRAY_SIZE);
      }

      words[lastElement].setWord(word);
      words[lastElement].setCount(1);
      lastElement++;
      
    }
  }

  // Print the word count
  output << "Words found: " << lastElement << "\n";
  output << "Array's max size: " << ARRAY_SIZE << "\n\n";
  for (int i = 0; i < lastElement; i++){
    output << words[i].getWord() << " - " << words[i].getCount() << '\n';
  }

  delete [] words;

  return 0;
}
