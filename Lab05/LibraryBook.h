// Your name
// Today's date
// Lab #5

// Ensure class isn't added more than once
// #ifndef LIBRARYBOOK_H
// #define LIBRARYBOOK_H

#include <string>
#include <iostream>
using namespace std;

// Write LibraryBook class here
class LibraryBook{
private:
	string title;
	string author;
	string isbn;
	bool checkedOut;

public:
	LibraryBook();
	LibraryBook(string _title, string _author, string _isbn);
	string getTitle();
	string getAuthor();
	string getIsbn();
	void checkOut();
	void checkIn();
	bool isCheckedOut();
	void printObject();
	void printISBN();
};

// Define LibraryBook functions here
// Define LibraryBook functions here
LibraryBook::LibraryBook(){
	author = "";
	title = "";
	isbn = "";
	checkedOut = false;
}

LibraryBook::LibraryBook(
	string _title, string _author, string _isbn){

	author = _author;
	title = _title;
	isbn = _isbn;
	checkedOut = false;
}

string LibraryBook::getTitle(){
	return title;
}
string LibraryBook::getAuthor(){
	return author;
}
string LibraryBook::getIsbn(){
	return isbn;
}

void LibraryBook::checkOut(){
	checkedOut = true;
}
void LibraryBook::checkIn(){
	checkedOut = false;
}
bool LibraryBook::isCheckedOut(){
	return checkedOut;
}

// Test if the values have been set correctly
void LibraryBook::printObject(){
	cout << "Title: " << title << " Author: " << author;
	cout << " ISBN: " << isbn << "\n";
}

void LibraryBook::printISBN(){
	cout << ">> " << isbn << "\n";
}

// This matches #ifndef at beginning of the file, so leave it in
// #endif















