// Word.h
// @debarron
// 03/15/2017
// Class to store words

#include <string>
using namespace std;

class Word{
private:
	string word;
	int count;

public:
	Word();
	Word(string _word, int _count);
	string getWord();
	int getCount();
	void setWord(string _word);
	void setCount(int _count);
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
string Word::getWord(){
	return word;
}
int Word::getCount(){
	return count;
}
void Word::setCount(int _count){
	count = _count;
}
void Word::setWord(string _word){
	word = _word;
}
void Word::increment(){
	count++;
}









