// LibraryBook.cpp
// Today's date
// Lab #5

#include "LibraryBook.h"
#include <string>
#include <iostream>
using namespace std;

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













