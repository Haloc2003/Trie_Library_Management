#include <iostream>
#include <string>
#include "LibraryTrie.h"

using namespace std;

int main()
{
	string title, author, genre;
	int page_number, release_date;
	int choice = 0;
	LibraryTrie library;

	
	while (choice != 3)
	{

		cout << "Would you like to add a book or search a book?: " << "\n" << "1. To add a new book. " << "\n" << "2. To search a book. " << "\n" << "3. To quit. " << endl;
		cin >> choice;

		if (choice == 3)
			break;

		if (choice == 1)
		{
			cin.ignore();
			cout << "Enter Title: ";
			getline(cin, title);

			cout << "Enter author: ";
			getline(cin, author);

			cout << "Enter genre: ";
			getline(cin, genre);

			cout << "Enter release date: ";
			cin >> release_date;

			cout << "Enter page number: ";
			cin >> page_number;
			cout << endl;

			library.NewBook(title, author, genre, release_date, page_number);

			choice = 0;
		}

		if (choice == 2)
		{
			string searchTitle;
			cin.ignore();
			cout << "Enter a book title to serach: ";
			getline(cin, searchTitle);

			library.printBookInfo(searchTitle);

			choice = 0;

		}

	}

}
