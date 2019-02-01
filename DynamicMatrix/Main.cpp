// Main.cpp
// debarron
// 03/11/2017
// A dynamic matrix example

#include <fstream>
#include <iostream>
#include "Matrix.h"

using namespace std;

void readMatrixFromFile(istream &input, Matrix &m){
	int value;

	for(int i = 0; i < m.getRows(); i++){
		for(int j = 0; j < m.getCols(); j++){
			input >> value;
			m.setValue(i, j, value);
		}
	}
}



int main(){
	int rows, cols;
	int matrixCounter = 0;
	ifstream input("input.txt");

	int listCount = 2;
	Matrix *list = new Matrix[listCount];

	while(!input.eof()){
		input >> rows >> cols;
		Matrix first(rows, cols);
		Matrix second(rows, cols);
		Matrix sum(rows, cols);

		readMatrixFromFile(input, first);
		readMatrixFromFile(input, second);

		// Simple test
		// cout << "\n>> Print the first matrix\n";
		// first.print(cout);
		// cout << "\n\n>> Print the second matrix\n";
		// second.print(cout);

		for (int i = 0; i < rows; i++){
			for (int j = 0; j < cols; j++){
				int newVal = first.getValue(i,j) + second.getValue(i,j);
				sum.setValue(i, j, newVal);
			}
		}

		cout << "\n\n>> Print the sum matrix\n";
		sum.print(cout);

		if(matrixCounter == (listCount - 1)){
			Matrix *aux = list;
			int oldSize = listCount;

			listCount *= 2;
			list = new Matrix[2];

			for(int i = 0; i < oldSize; i++){
				list[i] = aux[i];
			}

			delete[] aux;
		}
		list[matrixCounter++] = sum;
	}

	for (int i = 0; i < matrixCounter; i++){
		cout << "\n>> Printin matrix list at " << i << '\n';
		list[i].print(cout);
	}
	

	return 0;
}