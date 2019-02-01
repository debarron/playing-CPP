// Sarah Withee
// 2/24/14
// Lab 5

#include "Fraction.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// This file will be included when grading
// For testing, feel free to modify this file to ensure your class is 
// working.


int main() {
	// Input/output files
	ifstream fin("input.txt");
	ofstream fout("output.txt");

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
		// Read in two fractions and the operator to perform
		Fraction fract1, fract2;
		char oper;
		fin >> fract1 >> oper >> fract2;
		
		// Print out original functions read in
        cout << fract1 << " " << oper << " " << fract2 << " = " ;


		
		// Do math on them
		switch(oper)
		{
		case '+':
			fout << fract1 + fract2 << '\n';
			cout << fract1 + fract2 << '\n';
			break;

		case '-':
			fout << fract1 - fract2 << '\n';
			cout << fract1 - fract2 << '\n';
			break;

		case '*':
			fout << fract1 * fract2 << '\n';
			cout << fract1 * fract2 << '\n';
			break;

		case '/':
			fout << fract1 / fract2 << '\n';
			cout << fract1 / fract2 << '\n';
			break;

		case '=':
			if(fract1 == fract2){
				fout << "True" << '\n';
				cout << "True" << '\n';
			}
			else{
				fout << "False" << '\n';
				cout << "False" << '\n';
			}
			break;

		}
	}

	// Close files
	fin.close();
	fout.close();

	// Quit without error
	return 0;

}