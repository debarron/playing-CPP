// Main.cpp
// Dynamic allocation
// debarron

#include <iostream>

using namespace std;

/**
This example includes the creation of a dynamic array and matrix.
It reads data to create the matrix dynamically. Also, the program 
sets values to each possition in the array and matrix.

Finally, the program outputs the matrix to the screen and exits.
**/

int main(){

	// Think of the stars at the number of dimenssions in your array
	int *dynamicArray; // This is how you declare a dynamic array
	int **dynamicMatrix; // This is how you declare a 2d dynamic array

	// Variables keep track of how many elements we need
	int arraySize;
	int rows, cols;

	cout << "--- DYNAMIC MEMORY EXAMPLE ---\n\n";

	cout << "# DYNAMIC ARRAY EXAMPLE\n";
	cout << "Indicate the size of your array: ";
	cin >> arraySize;

	// Initialize the dynamic array
	dynamicArray = new int[arraySize];

	// Validate if memory was assigned succesfully
	if(dynamicArray == nullptr){
		cout << " >> \t ERROR can not assign " << arraySize << " elements\n";
		exit(1);
	}
	else{
		cout << " >> \t Memory assigned succesfully\n";
	}

	// Get values for every element in the dynamic array
	for (int i = 0; i < arraySize; i++){
		cout << "Give a value to Array[" << i << "]: ";
		cin >> dynamicArray[i];
	}
	cout << "\n\nPrinting the array values: ";
	for (int i = 0; i < arraySize; i++){
		cout << dynamicArray[i] << " ";
	}
	cout << "\n\n";


	/**
	DYNAMIC MATRIX EXAMPLE STARTS HERE
	Note:
		Keep in mind that a matrix is an array of arrays
	**/

	cout << "# DYNAMIC MATRIX EXAMPLE\n";
	cout << "Indicate the number of Rows: ";
	cin >> rows;
	cout << "Indicate the number of Cols: ";
	cin >> cols;

	// Create memory for the dynamicMatrix and validate assignment
	dynamicMatrix = new int*[rows];
	if(dynamicMatrix == nullptr){
		cout << " >> \t ERROR can not assign " << rows << " elements\n";
		exit(1);
	}
	else{
		cout << " >> \t Memory assigned succesfully\n";
	}

	// The next step is to ask memory to store each row.
	for(int i = 0; i < rows; i++){
		dynamicMatrix[i] = new int[cols];

		if(dynamicMatrix[i] == nullptr){
			cout << " >> \t ERROR can not assign " << cols << " elements\n";
			exit(1);
		}
		else{
			cout << " >> \t Memory assigned succesfully\n";
		}
	}

	// Assign values to the dynamicMatrix
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			cout << "Give value for [" << i << "][" << j << "]: ";
			cin >> dynamicMatrix[i][j];
		}
	}
	cout << "\n";

	// Print the dynamicMatrix
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			cout << " " << dynamicMatrix[i][j] << " ";
		}
		cout << " \n";
	}

	return 0;
}