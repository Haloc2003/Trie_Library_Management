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




	while (choice != 5)
	{

		cout << "Would you like to add a book or search a book?: " << "\n" << "1. To add a new book. " << "\n" << "2. To search a book. " << "\n" << "3. To print all book titles. ";
		cout << "\n" << "4. To delete a book" << "\n" << "5. To quit." << endl;
		cin >> choice;

		if (choice == 5)
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

			choice = 0;
		}

		if (choice == 4)
		{
			string bookToDelete;
			cin.ignore();
			cout << "Enter the title of the book you want to delete: " << endl;
			getline(cin, bookToDelete);

			if (library.DeleteBook(bookToDelete))
			{
				cout << "Book Deleted. " << "\n";
			}
			else
			{
				cout << "Book not found. " << "\n";
			}

			choice = 0;
			
			
		}

	}





}