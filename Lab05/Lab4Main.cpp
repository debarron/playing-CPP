// Sarah Withee
// February 17, 2014
// Lab #4

#include "LibraryBook.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main() {
	ifstream finBooks("books.txt");
	ifstream finISBN("isbns.txt");
	ofstream fout("checkedout.txt");
	string fileInput;

	int numBooks;
	LibraryBook *books;//object pointer
	books = new LibraryBook[15];//points to 15 object (like an array)

	//or you can use a dummy object, initialize it using the second constructor then initializing our array book object to the dummy book

	// Check for file errors first
	if(!finBooks || !finISBN)
	{
		cout << "Error opening input files!\n";
		system("pause");
		return 1;
	}

	// Load in books into array
	numBooks = 0;
	while(!finBooks.eof()) 
	{
		string title, author, isbn;
		getline(finBooks,title);
		getline(finBooks,author);
		getline(finBooks,isbn);
		
		books[numBooks] = LibraryBook(title, author, isbn);
		numBooks++;
	}

	// Check in/out books
	while(!finISBN.eof())
	{
		string isbn;
		finISBN >> isbn;
		for(int i = 0; i < numBooks; i++)
		{
			if(books[i].getIsbn() == isbn)
			{
				if(books[i].isCheckedOut())
					books[i].checkIn();
				else
					books[i].checkOut();
			}
		}
	}

	// Report of checked out books
	fout << "Books checked out:\n------------------\n\nTitle\tAuthor\tISBN\n";
	for(int i = 0; i < numBooks; i++)
	{
		// if(books[i].isCheckedOut())
			fout << books[i].getTitle() << "\t" << books[i].getAuthor() << "\t" << books[i].getIsbn() << "\n";
	}

	
	finBooks.close();
	finISBN.close();
	fout.close();

	return 0;
}
