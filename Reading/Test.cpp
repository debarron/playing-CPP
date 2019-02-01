//Test.cpp

#include <iostream>
#include <fstream>

using namespace std;

void practice03(){
	ifstream input("data.txt");

	int values1[20][20];
	int values2[20][20];
	int values3[20][20];
	int rows, cols, number;

	while(!input.eof()){

		input >> cols >> rows;

		// Cleaning
		for(int i = 0; i < rows; i++){
			for(int j = 0; j < cols; j++){
				values1[j][i] = 0;
				values2[j][i] = 0;
			}
		}

		// Reading to values1
		for(int i = 0; i < rows; i++){
			for(int j = 0; j < cols; j++){
				input >> number;
				values1[j][i] = values1[j][i] + number;
			}
		}	

		// Reading to values2
		for(int i = 0; i < rows; i++){
			for(int j = 0; j < cols; j++){
				input >> number;
				values2[j][i] = values2[j][i] + number;
			}
		}	


		// Set sum in values3 
		for(int i = 0; i < rows; i++){
			for(int j = 0; j < cols; j++){
				values3[j][i] = values2[j][i] + values1[j][i];
			}
		}	

		cout << "Matrix 1 is \n";
		for(int i = 0; i < rows; i++){
			for(int j = 0; j < cols; j++){
				cout << values1[j][i] << " ";
			}
			cout << "\n";
		}

		cout << "\n\nMatrix 2 is \n";
		for(int i = 0; i < rows; i++){
			for(int j = 0; j < cols; j++){
				cout << values2[j][i] << " ";
			}
			cout << "\n";
		}


		cout << "\n\nMatrix 3 is \n";
		for(int i = 0; i < rows; i++){
			for(int j = 0; j < cols; j++){
				cout << values3[j][i] << " ";
			}
			cout << "\n";
		}
	}
}

int main(){

	ifstream input("data.txt");

	while(!input.eof())
		practice03();
	
	return 0;
}
