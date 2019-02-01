// Lab05_dl544.cpp
// debarron
// Classes and files

// X 1 Define a class LibraryBook, with attributes and functions
// X 2 Test if the object is well implemented
// -> 3 Read data from the files, check for mistakes
// 4 Initialize objects from data files.

#include <string>
#include <iostream>
#include <fstream>

#include "LibraryBook.h"

void printBook(ostream &out, LibraryBook b){
	out << "Title: " << b.getTitle(); 
	out << " Author: " << b.getAuthor();
	out << " ISBN: " << b.getISBN() << "\n";
}

string cleanUp(string _str){
	string result = _str;
	for (int i = 0; i < result.length(); i++){
		int v = ((int)result[i]);

		if(v < 32) result.erase(i, 1);
	}

	return result;
}

int main(){
	LibraryBook defult;
	LibraryBook params("C++", "Daniel", "123435");

	ifstream inputBooks("books.txt");
	if(inputBooks.fail()){
		cout << "Error while reading the books.txt file\n";
		exit(1);
	}

	// Array to store books
	LibraryBook books[100];
	int index = 0;
	while(!inputBooks.eof()){
		string _title, _author, _isbn;

		getline(inputBooks, _title);
		getline(inputBooks, _author);
		getline(inputBooks, _isbn);

		LibraryBook newBook(
			cleanUp(_title), 
			cleanUp(_author), 
			cleanUp(_isbn)
			);
		books[index] = newBook;
		// printBook(books[index]);

		index++;
	}
	inputBooks.close();

	// Read the isbns
	ifstream inputIsbns("isbns.txt");
	if(inputIsbns.fail()){
		cout << "Error while reading isbns.txt\n";
		exit(1); 
	}
	while(!inputIsbns.eof()){
		string _isbn, isbn;
		inputIsbns >> _isbn;
		// You don't need to do this
		isbn = cleanUp(_isbn);

		// Filtering the books
		for (int i = 0; i < index; i++){
			
			if(books[i].getISBN() == isbn){
				if(books[i].isCheckedOut()){
					books[i].checkIn();
				}
				else{
					books[i].checkOut();
				}
			}
		}
	}

	ofstream outputFile("myOutput.txt");
	if(outputFile.fail()){
		cout << "Error while creating the myOutput.txt file\n";
		exit(1);
	}

	cout << "Books checked out: \n";
	cout << "------------------ \n";
	cout << "\n";
	cout << "Title \t Author \t ISBN\n";

	outputFile << "Books checked out: \n";
	outputFile << "------------------ \n";
	outputFile << "\n";
	outputFile << "Title \t Author \t ISBN\n";
	for (int i = 0; i < index; ++i)	{
		
		if(books[i].isCheckedOut()){
			printBook(cout, books[i]);
			printBook(outputFile, books[i]);
		}
	}

}










