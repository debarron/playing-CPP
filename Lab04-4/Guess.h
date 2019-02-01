// Guess.h
#ifndef MY_GUESS
#define MY_GUESS

class Guess{
private:
	int number;
	bool guessCorrectly;

public:
	Guess();
	void setNumer(int _number);
	bool makeGuess(int _guess);
	bool getGuess();
};

#endif