// Your Name
// Today's date
// Lab 5

#include <iostream>
using namespace std;

class Fraction
{

// Add the variables and functions you need to. getGCD and reduce are 
// provided for you.

private:
	int denominator, numerator;
	int getGCD( int num1, int num2 );

public:
	void reduce();
	Fraction();
	const Fraction operator+(Fraction rhs);
	const Fraction operator-(Fraction rhs);
	const Fraction operator*(Fraction rhs);
	const Fraction operator/(Fraction rhs);
	bool operator==(Fraction rhs);
	friend ostream& operator<<(ostream& output, const Fraction& frac);
	friend istream& operator>>(istream& input, Fraction& frac);
};
















