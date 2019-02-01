// BasicExample.cpp
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

#define ARRAY_SIZE 1000

using namespace std;

int mainBasic(){
  string words[ARRAY_SIZE];
  int wordCount[ARRAY_SIZE];
  int lastElement = 0;

  string word;
  ifstream input("input.txt");
  ofstream output("myOutput.txt");

  // Clean the memory
  for(int i = 0; i < ARRAY_SIZE; i++){
    words[i] = "";
    wordCount[i] = 0;
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
    for(int i = 0; i < ARRAY_SIZE; i++){
      if(word == words[i]){
        found = true;
        foundIndex = i;
      }
    }

    if(found){ // Of found, increment the counter
      wordCount[foundIndex]++;
    }
    else{ // Add the word to the list

      if(lastElement < ARRAY_SIZE){
        words[lastElement] = word;
        wordCount[lastElement] = 1;
        lastElement++;
      }
      else{
        output << ">> WARNING, we don't have enough memory. Ignoring: " << word << '\n';
      }
    }
  }

  // Print the word count
  output << "Words found: " << lastElement << "\n";
  output << "Array's max size: " << ARRAY_SIZE << "\n\n";
  for (int i = 0; i < ARRAY_SIZE; i++){
    output << words[i] << " - " << wordCount[i] << '\n';
  }

  return 0;
}
