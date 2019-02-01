// Your name
// Today's date
// Lab #4

#include "LibraryBook.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main() {
	// File stream variables
    ifstream finBooks("books.txt");
	ifstream finISBN("isbns.txt");
	ofstream fout("checkedout.txt");

	// Check for file errors first
	if(!finBooks || !finISBN)
	{
		cout << "Error opening input files!\n";
		system("pause");
		return 1;
	}


    // Write program in here




	// Close the files at the end
	finBooks.close();
	finISBN.close();
	fout.close();

    // End program
	return 0;
}
