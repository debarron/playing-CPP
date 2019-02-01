// Your Name
// Today's date
// Lab 5

#include "Fraction.h"
#include <iostream>
#include <string>
using namespace std;

// Find the greatest common denominator (GCD)
// For reducing
Fraction::Fraction(){
	numerator = 0;
	denominator = 0;
}

ostream& operator<<(ostream& output, const Fraction& frac){
	output << frac.numerator << " / " << frac.denominator;
	return output;
}

istream& operator>>(istream& input, Fraction& frac){
	char slash;
	input >> frac.numerator >> slash >> frac.denominator;
	return input;
}

int Fraction::getGCD( int num1, int num2 )
{
	int remainder = num2 % num1;
	if ( remainder != 0 )
		return getGCD( remainder, num1 );
	return num1;
} 

// Reduce/simplify a fraction
void Fraction::reduce()
{
    // Alter this function later to adjust for negative values
	int gcd = getGCD(numerator, denominator);
	numerator /= gcd;
	denominator /= gcd;
} 

const Fraction Fraction::operator+(Fraction rhs){
	Fraction c;

	reduce();
	rhs.reduce();

	c.denominator = denominator * rhs.denominator;
	c.numerator = (numerator * rhs.denominator) + (rhs.numerator * denominator);

	c.reduce();
	return c;
}

const Fraction Fraction::operator-(Fraction rhs){
	Fraction c;

	reduce();
	rhs.reduce();

	c.denominator = denominator * rhs.denominator;
	c.numerator = (numerator * rhs.denominator) - (rhs.numerator * denominator);

	c.reduce();
	return c;
}

const Fraction Fraction::operator*(Fraction rhs){
	Fraction c;

	reduce();
	rhs.reduce();

	c.denominator = denominator * rhs.denominator;
	c.numerator = rhs.numerator * numerator;

	c.reduce();
	return c;
}

const Fraction Fraction::operator/(Fraction rhs){
	Fraction c;

	reduce();
	rhs.reduce();

	c.numerator = numerator * rhs.denominator;
	c.denominator = denominator * rhs.numerator;

	c.reduce();
	return c;
}

bool Fraction::operator==(Fraction frac){
	bool result = false;
	reduce();
	frac.reduce();

	if(numerator == frac.numerator && denominator == frac.denominator){
		result = true;
	}

	return result;
}



















