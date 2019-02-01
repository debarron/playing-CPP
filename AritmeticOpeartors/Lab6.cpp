// Daniel Lopez
// 03/10/2017
// Lab 6

#include "Fraction.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int getGCD( int num1, int num2 ){
	int remainder = num2 % num1;
	if ( remainder != 0 )
		return getGCD( remainder, num1 );
	return num1;
} 

// Reduce/simplify a fraction
void reduce(int &numerator, int &denominator){
    // Alter this function later to adjust for negative values
	int gcd = getGCD(numerator, denominator);
	numerator /= gcd;
	denominator /= gcd;
} 

void summation(
	int _fracNumeratorLeft,
	int _fracDenominatorLeft, 
	int _fracNumeratorRight, 
	int _fracDenominatorRight){

	// Reduce the left Fraction
	reduce(_fracNumeratorLeft, _fracDenominatorLeft);

	// Reduce the right Fraction
	reduce(_fracNumeratorRight, _fracDenominatorRight);

	int newDenominator = _fracDenominatorLeft * _fracDenominatorRight;
	int newNumerator = 
	(_fracNumeratorLeft * _fracDenominatorRight) + 
	(_fracNumeratorRight * _fracDenominatorLeft);

	cout << newNumerator << " / " << newDenominator << '\n';
}

void Minus(
	int _fracNumeratorLeft,
	int _fracDenominatorLeft, 
	int _fracNumeratorRight, 
	int _fracDenominatorRight){

	// Reduce the left Fraction
	reduce(_fracNumeratorLeft, _fracDenominatorLeft);

	// Reduce the right Fraction
	reduce(_fracNumeratorRight, _fracDenominatorRight);

	int newDenominator = _fracDenominatorLeft * _fracDenominatorRight;
	int newNumerator = 
	(_fracNumeratorLeft * _fracDenominatorRight) - 
	(_fracNumeratorRight * _fracDenominatorLeft);

	cout << newNumerator << " / " << newDenominator << '\n';
}

void multiplication(
	int _fracNumeratorLeft,
	int _fracDenominatorLeft, 
	int _fracNumeratorRight, 
	int _fracDenominatorRight){

	// Reduce the left Fraction
	reduce(_fracNumeratorLeft, _fracDenominatorLeft);

	// Reduce the right Fraction
	reduce(_fracNumeratorRight, _fracDenominatorRight);

	int newDenominator = _fracDenominatorLeft * _fracDenominatorRight;
	int newNumerator = _fracNumeratorLeft * _fracNumeratorRight ;

	cout << newNumerator << " / " << newDenominator << '\n';
}

void division(
	int _fracNumeratorLeft,
	int _fracDenominatorLeft, 
	int _fracNumeratorRight, 
	int _fracDenominatorRight){

	// Reduce the left Fraction
	reduce(_fracNumeratorLeft, _fracDenominatorLeft);

	// Reduce the right Fraction
	reduce(_fracNumeratorRight, _fracDenominatorRight);

	int newNumerator = _fracNumeratorLeft * _fracDenominatorRight;
	int newDenominator = _fracDenominatorLeft * _fracNumeratorRight ;

	reduce(newNumerator, newDenominator);
	cout << newNumerator << " / " << newDenominator << '\n';
}

void equal(
	int _fracNumeratorLeft,
	int _fracDenominatorLeft, 
	int _fracNumeratorRight, 
	int _fracDenominatorRight){

	// Reduce the left Fraction
	reduce(_fracNumeratorLeft, _fracDenominatorLeft);

	// Reduce the right Fraction
	reduce(_fracNumeratorRight, _fracDenominatorRight);

	if(_fracNumeratorLeft == _fracNumeratorRight &&
		_fracDenominatorRight == _fracDenominatorLeft)
		cout << "True\n";
	else
		cout << "False\n";
}



int main() {
	// Input/output files
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	// Abstract a fraction BASIC APPROACH
	// int fracNumeratorLeft;
	// int fracDenominatorLeft;
	// int fracNumeratorRight;
	// int fracDenominatorRight;
	

	// Throw error if can't open input file
	if(!fin)
	{
		cerr << "Error opening input file!";
		system("pause");
		return 1;
	}

	// While there's data in the file, read in a line and calcuate it
	while(fin.good())
	{
		char slash;
		int num, denom;
		char operation;

		Fraction left, right;
		// Reading the values for the left fraction

		// fin >> num;
		// fin >> slash;
		// fin >> denom;
		// Fraction left(num, denom);

		fin >> left;
		// Read the arithmetic operator
		fin >> operation;

		fin >> right;
		// Reading the values for the right fraction
		// fin >> num;
		// fin >> slash;
		// fin >> denom;
		// Fraction right(num, denom);

		cout << left.toString();
		cout << " " << operation << " ";
		cout << right.toString();
		cout << " = ";

		switch(operation){
			case '+': {
				Fraction c = left + right;
				cout << c << '\n';
				// Fraction c = left.addition(right);
				// cout << c.toString() << '\n';
				// summation(
				// 	fracNumeratorLeft, 
				// 	fracDenominatorLeft,
				// 	fracNumeratorRight,
				// 	fracDenominatorRight
				// );
			break;
			}

			case '-':{
				Fraction c = left - right;
				cout << c << '\n';
				// Fraction c = left.subtraction(right);
				// cout << c.toString() << '\n';
				// Minus(
				// 	fracNumeratorLeft, 
				// 	fracDenominatorLeft,
				// 	fracNumeratorRight,
				// 	fracDenominatorRight
				// );
				break;
			}
			case '/':
			{
				Fraction c = left / right;
				cout << c << '\n';

				// Fraction c = left.division(right);
				// cout << c.toString() << '\n';

				// division(
				// 	fracNumeratorLeft, 
				// 	fracDenominatorLeft,
				// 	fracNumeratorRight,
				// 	fracDenominatorRight
				// );
				break;
				}
			case '*':
				{
					Fraction c = left * right;
					cout << c << '\n';
					// Fraction c = left.multiplication(right);
					// cout << c.toString() << '\n';
					// multiplication(
					// 		fracNumeratorLeft, 
					// 		fracDenominatorLeft,
					// 		fracNumeratorRight,
					// 		fracDenominatorRight
					// 	);
					break;
				}
			case '=':
				{
					if(left == right)
						cout << "They are equal\n";
					else
						cout << "They are NOT equal\n";

					// if(left.compare(right))
					// 	cout << "They are equal\n";
					// else
					// 	cout << "They are NOT equal\n";
				}

				// equal(
				// 	fracNumeratorLeft, 
				// 	fracDenominatorLeft,
				// 	fracNumeratorRight,
				// 	fracDenominatorRight
				// );
				break;
		}		



		// // Read in two fractions and the operator to perform
		// Fraction fract1, fract2;
		// char oper;
		// fin >> fract1 >> oper >> fract2;
		
		// // Print out original functions read in
  //       cout << fract1 << " " << oper << " " << fract2 << " = " ;


		
		// // Do math on them
		// switch(oper)
		// {
		// case '+':
		// 	fout << fract1 + fract2 << '\n';
		// 	cout << fract1 + fract2 << '\n';
		// 	break;

		// case '-':
		// 	fout << fract1 - fract2 << '\n';
		// 	cout << fract1 - fract2 << '\n';
		// 	break;

		// case '*':
		// 	fout << fract1 * fract2 << '\n';
		// 	cout << fract1 * fract2 << '\n';
		// 	break;

		// case '/':
		// 	fout << fract1 / fract2 << '\n';
		// 	cout << fract1 / fract2 << '\n';
		// 	break;

		// case '=':
		// 	if(fract1 == fract2){
		// 		fout << "True" << '\n';
		// 		cout << "True" << '\n';
		// 	}
		// 	else{
		// 		fout << "False" << '\n';
		// 		cout << "False" << '\n';
		// 	}
		// 	break;
		// }
	}

	// Close files
	fin.close();
	fout.close();

	// Quit without error
	return 0;

}