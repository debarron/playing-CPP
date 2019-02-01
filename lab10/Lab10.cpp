// debarron
// 4/12/2017
// A example of datastructures

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <fstream>

#include "Word.h"
using namespace std;

void vectorExample(){
  ifstream input("input.txt");

  string myWord;
  vector<Word> words;
  vector<Word>::iterator wit;

  if(input.fail()){
    cout << "Error while opening the file";
    exit(1);
  }

  while(input >> myWord){
    bool insert = true;

    for(wit = words.begin(); wit != words.end(); wit++){
      if(myWord == wit->getWord()){
        wit->increment();
        insert = false;
      }
    }

    if(insert == true){
      Word w(myWord);
      w.increment();
      words.push_back(w);
    }
  }
  input.close();

  // Print the results
  cout << "Found : " << words.size() << endl;
  for(wit = words.begin(); wit != words.end(); wit++){
    cout << wit->getWord() << " " << wit->getCount() << endl;
  }

}

//Map example
int main(){
  ifstream input("input.txt");

  string myWord;
  map<string,int> words;
  map<string,int>::iterator wit;

  if(input.fail()){
    cout << "Error while opening the file";
    exit(1);
  }

  while(input >> myWord){
    words[myWord]++;
  }
  input.close();

  // Search for a given key k
  const string test = "CLIENT";
  wit = words.find(test);

  // No such key
  if(wit == words.end()){
    cout << "This key: " << test <<", does not exists\n";
  }
  else{ //Found key
    cout << (*wit).first << " " <<(*wit).second << endl;
  }
  cout << "##########################" << endl;

  // Print the results
  cout << "Found : " << words.size() << endl;
  for(wit = words.begin(); wit != words.end(); wit++){
    cout << (*wit).first << " " << (*wit).second << endl;
  }

  return 0;
}



//
// int main_(){
//   vector<int> v;
//   vector<int>::iterator it;
//
//   it = v.begin();
//   v.push_back(30);
//   for(int i = 0; i < 10; i++){
//     v.push_back(i*2);
//   }
//
//   int i = 0;
//   for(it = v.begin(); it != v.end(); it++){
//     cout << "Element " << i << " = " << *it << "\n";
//     i++;
//   }
//
//   // Map operations
//   map<string, int> m;
//   m["message"] = 2;
//   m["grade"] = 3;
//   m["test"] = 5;
//
//   cout << "\n\n";
//   map<string, int>::iterator it2;
//   for(it2 = m.begin(); it2 != m.end(); it2++){
//     cout << " Elem. " << (*it2).first << " " << (*it2).second <<"\n";
//   }
//
//
//
// }
