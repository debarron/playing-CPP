// LibraryBook.h

#ifndef MY_LIBRARY_BOOK
#define MY_LIBRARY_BOOK

#include <string>
using namespace std;

// Here we define the class
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
	string getISBN();
	void checkOut();
	void checkIn();
	bool isCheckedOut();
};

// Defining the behavior of the class

LibraryBook::LibraryBook(){
	author = "";
	title = "";
	isbn = "";
	checkedOut = false;
}

LibraryBook::LibraryBook(string _title, string _author, string _isbn){
	author = _author;
	title = _title;
	isbn = _isbn;
	checkedOut = false;
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

string LibraryBook::getISBN(){
	return isbn;
}
string LibraryBook::getTitle(){
	return title;
}
string LibraryBook::getAuthor(){
	return author;
}


#endif













