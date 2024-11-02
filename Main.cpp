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




	while (choice != 8)
	{

		cout << "Would you like to add a book or search a book?: " << "\n" << "1. To add a new book. " << "\n" << "2. To search a book. " << "\n" << "3. To print all book titles. ";
		cout << "\n" << "4. To delete a book(placeholder)" << "\n" << "5. Print a book to a the LibraryInfo.txt file.\n" << "6. Print all books to the Library.txt file\n" << "7. Import Book Info from File.\n" << "8. To quit." << endl << "Enter Selection: ";
		cin >> choice;

		if (choice == 8)
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
			cout << "Enter a book title to search: ";
			getline(cin, searchTitle);

			library.printBookInfo(searchTitle);
			cout << endl;

			choice = 0;

		}

		if (choice == 3)
		{

			if (library.isEmpty())
			{
				cout << "No books found. " << endl;
			}
			else
				library.printAllBooks();
		}

		if (choice == 5)
		{
			string searchTitle;
			cin.ignore();
			cout << "Enter a book title to search: ";
			getline(cin, searchTitle);

			library.PrintBookInfoToFile(searchTitle);
			cout << "Printed to File" << endl;

			choice = 0;

		}

		if (choice == 6)
		{

			if (library.isEmpty())
			{
				cout << "No books found. " << endl;
			}
			else
			{
				library.PrintAllToFile();
				cout << "Printed to File" << endl;
			}

			
		}

		if (choice == 7)
		{
			string filename;

			cout << "Enter File Name (include .txt at the end): ";
			cin.ignore();
			getline(cin, filename);
			

			library.ImportFromFile(filename);

			cout << "File imported.\n";
		}

		system("pause");
	
		system("cls");

	}





}