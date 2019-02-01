// Word.h

#include <string>

using namespace std;

class Word{
private:
  string word;
  int count;

public:
  Word();
  Word(string _word, int _count);
  void setCount(int _count);
  void setWord(string _word);
  int getCount();
  string getWord();
  void increment();
};

Word::Word(){
  word = "";
  count = 0;
}

Word::Word(string _word, int _count){
  word = _word;
  count = _count;
}

void Word::setCount(int _count){
  count = _count;
}

void Word::setWord(string _w){
  word = _w;
}

string Word::getWord(){
  return word;
}

int Word::getCount(){
  return count;
}

void Word::increment(){
  count++;
}
