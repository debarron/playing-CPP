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
	string getWord();
	int getCount();
	void setCount(int _count);
	void setWord(string _word);
	void increment();
};

Word::Word(){
	count = 0;
	word = "";
}

Word::Word(string _word, int _count){
	count = _count;
	word = _word;
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










