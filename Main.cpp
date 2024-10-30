

#include <iostream>
#include <string>
#include "LibraryTrie.h"

using namespace std;

int main()
{
	string title, author, genre;
	int page_number, release_date, choice = 0;
	LibraryTrie library;

	while (choice != 1)
	{
		cout << "Enter Title: ";
		getline(cin, title);

		cout << "Enter Author: ";
		getline(cin, author);

		cout << "Enter Genre: ";
		getline(cin, genre);
		cin.ignore();

		cout << "Enter Page Number: ";
		cin >> page_number;

		cout << "Enter Release Year: ";
		cin >> release_date;

		library.NewBook(title, author, genre, release_date, page_number);//////////

		cout << "Would you like to enter another book? (1 if no, 2 if yes): ";
		cin >> choice;

	}


		




}