// debarron
// 03/10/2017

#include <string>
#include <iostream>

using namespace std;

class Fraction{
private:
	int numerator, denominator;

public:
	Fraction();
	Fraction(int _num, int _den);
	int getGCD( int num1, int num2 );
	void reduce();
	Fraction addition(Fraction rhs);
	Fraction subtraction(Fraction rhs);
	Fraction multiplication(Fraction rhs);
	Fraction division(Fraction rhs);
	bool compare(Fraction rhs);
	string toString();
	friend ostream& operator<<(ostream &out, const Fraction &frac);
	friend istream& operator>>(istream &in, Fraction &frac);

	// Defining arithmetic ops
	const Fraction operator+(Fraction rhs);
	const Fraction operator-(Fraction rhs);
	const Fraction operator*(Fraction rhs);
	const Fraction operator/(Fraction rhs);
	bool operator==(Fraction rhs);

};

ostream& operator<<(ostream &out, const Fraction &frac){
	out << frac.numerator;
	out << " / ";
	out << frac.denominator;
	return out;
}

istream& operator>>(istream &in, Fraction &frac){
	char slash;

	in >> frac.numerator >> slash >> frac.denominator;
	return in;
}


string Fraction::toString(){
	string result = 
			to_string(numerator) + " / " +
			to_string(denominator);

	return result;
}

Fraction::Fraction(){
	numerator = 0;
	denominator = 0;
}

Fraction::Fraction(int _num, int _den){
	numerator = _num;
	denominator = _den;
}

int Fraction::getGCD(int num1, int num2){
	int remainder = num2 % num1;
	if ( remainder != 0 )
		return getGCD( remainder, num1 );
	return num1;
}

void Fraction::reduce(){
	// Alter this function later to adjust for negative values
	int gcd = getGCD(numerator, denominator);
	numerator /= gcd;
	denominator /= gcd;
}

Fraction Fraction::addition(Fraction rhs){
	// Reduce the left Fraction
	reduce();

	// Reduce the right Fraction
	rhs.reduce();

	int newDenominator = denominator * rhs.denominator;
	int newNumerator = 
	(numerator * rhs.denominator) + (rhs.numerator * denominator);

	Fraction result(newNumerator, newDenominator);
	return result;
	//cout << newNumerator << " / " << newDenominator << '\n';
}

Fraction Fraction::subtraction(Fraction rhs){
	// Reduce the left Fraction
	reduce();

	// Reduce the right Fraction
	rhs.reduce();

	int newDenominator = denominator * rhs.denominator;
	int newNumerator = 
	(numerator * rhs.denominator) - (rhs.numerator * denominator);

	Fraction result(newNumerator, newDenominator);
	return result;
	//cout << newNumerator << " / " << newDenominator << '\n';
}

Fraction Fraction::multiplication(Fraction rhs){
	// Reduce the left Fraction
	reduce();

	// Reduce the right Fraction
	rhs.reduce();

	int newDenominator = denominator * rhs.denominator;
	int newNumerator = numerator  * denominator;

	Fraction result(newNumerator, newDenominator);
	return result;
	// cout << newNumerator << " / " << newDenominator << '\n';
}

Fraction Fraction::division(Fraction rhs){
	// Reduce the left Fraction
	reduce();

	// Reduce the right Fraction
	rhs.reduce();

	int newDenominator = denominator * rhs.numerator;
	int newNumerator = numerator  * rhs.denominator;

	Fraction result(newNumerator, newDenominator);
	return result;
	// cout << newNumerator << " / " << newDenominator << '\n';
}

bool Fraction::compare(Fraction rhs){
	reduce();

	// Reduce the right Fraction
	rhs.reduce();
	bool result;

	if(numerator == rhs.numerator && denominator == rhs.denominator)
		result = true;
	else
		result = false;

	return result;
}

// Defining arithmetic ops
const Fraction Fraction::operator+(Fraction rhs){
	// Reduce the left Fraction
	reduce();

	// Reduce the right Fraction
	rhs.reduce();

	int newDenominator = denominator * rhs.denominator;
	int newNumerator = 
	(numerator * rhs.denominator) + (rhs.numerator * denominator);

	Fraction result(newNumerator, newDenominator);
	return result;
	//cout << newNumerator << " / " << newDenominator << '\n';
}

const Fraction Fraction::operator-(Fraction rhs){
	// Reduce the left Fraction
	reduce();

	// Reduce the right Fraction
	rhs.reduce();

	int newDenominator = denominator * rhs.denominator;
	int newNumerator = 
	(numerator * rhs.denominator) - (rhs.numerator * denominator);

	Fraction result(newNumerator, newDenominator);
	return result;
	//cout << newNumerator << " / " << newDenominator << '\n';
}

const Fraction Fraction::operator*(Fraction rhs){
	// Reduce the left Fraction
	reduce();

	// Reduce the right Fraction
	rhs.reduce();

	int newDenominator = denominator * rhs.denominator;
	int newNumerator = numerator  * denominator;

	Fraction result(newNumerator, newDenominator);
	return result;
	// cout << newNumerator << " / " << newDenominator << '\n';
}

const Fraction Fraction::operator/(Fraction rhs){
	// Reduce the left Fraction
	reduce();

	// Reduce the right Fraction
	rhs.reduce();

	int newDenominator = denominator * rhs.numerator;
	int newNumerator = numerator  * rhs.denominator;

	Fraction result(newNumerator, newDenominator);
	return result;
	// cout << newNumerator << " / " << newDenominator << '\n';
}

bool Fraction::operator==(Fraction rhs){
	reduce();

	// Reduce the right Fraction
	rhs.reduce();
	bool result;

	if(numerator == rhs.numerator && denominator == rhs.denominator)
		result = true;
	else
		result = false;

	return result;
}








