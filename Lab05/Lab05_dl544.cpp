// Lab05_dl544.cpp

#include "LibraryBook.h"
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;


string cleanStr(string _input){
	string result = _input;
	for (int i = 0; i < result.length(); i++){
		if(result[i] == ' ' ) result.erase(i, 1);
	}
	return result;
}

string examine(string _str){
	string result = _str;
	for(int i = 0; i < _str.length(); i++){
		int v = ((int)_str[i]);
		if(v < 32){
			result.erase(i, 1);
		}
	}
	return result;
}


int main(){
	// 1. Creating the class LibraryBook.h
	// 2. Define the behavior of the new class
	// 3. Test the class, see if its correct
	

	// -> 4. Read from the file
	ifstream input("books.txt");
	if(input.fail()){
		cout << ">> Error while reading the file\n";
		exit(1); 
	}

	LibraryBook books[100];

	int index = 0;
	while(!input.eof()){
		string _title;
		string _author;
		string _isbn;

		getline(input, _title);
		getline(input, _author);
		getline(input, _isbn);

		books[index] = LibraryBook(
			examine(_title), 
			examine(_author), 
			examine(_isbn));
		index++;
	}
	input.close();


	// Read the ISBN file and see what books have been
	// checked in
	ifstream isbnInput("isbns.txt");
	if(isbnInput.fail()){
		cout << ">> Error while reading ISBNS\n";
		exit(1);
	}

	string isbns[100];
	int countIsbns = 0;
	while(!isbnInput.eof()){
		isbnInput >> isbns[countIsbns];
		countIsbns++;
	}
	isbnInput.close();



	// // We need to compare if that ISBN exists
	for (int i = 0; i < index; i++){
		int checked = 0;

		for (int j = 0; j < countIsbns; j++){
			string matchIsbn = isbns[j];

			if (matchIsbn.compare(books[i].getIsbn()) == 0) {
				checked++;
				// cout << matchIsbn << " " << books[i].getIsbn() << "\n";
				// if(books[i].isCheckedOut() == false)	
				// 	books[i].checkIn();
				// else
				// 	books[i].checkOut();
			}
		}

		cout << "Count is " << checked << " ";
		books[i].printObject();
		cout << "---\n";

		// cout << ">> " << books[i].getTitle() << " count " << checked << "\n";
	}

	// 	books[i].printISBN();
	// 	cout << "Checked: " << checked << "\n ---- \n";
	// }


	// // 5. Print the output
	// for (int i = 0; i < index; i++){
	// 	// if (books[i].isCheckedOut() == true){
	// 		books[i].printObject();
	// 	// }
	// }
}











