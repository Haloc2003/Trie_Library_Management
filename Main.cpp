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




	while (choice != 6)
	{

		cout << "Would you like to add a book or search a book?: " << "\n" << "1. To add a new book. " << "\n" << "2. To search a book. " << "\n" << "3. To print all book titles. ";
		cout << "\n" << "4. To delete a book" << "\n" <<"5. To edit a book" "\n"<< "6. To quit." << endl;
		cin >> choice;

		if (choice == 6)
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


			//adding error handling
			do
			{
				cout << "Enter release year: ";
				cin >> release_date;

				if (cin.fail())
				{
					
					cout << "ERROR, Enter integer: \n";
					
					cin.clear();

					cin.ignore(numeric_limits<streamsize>::max(), '\n');

					cin >> release_date;
				}


			} while (cin.fail());
		
			
			do
			{

				cout << "Enter page number: ";
				cin >> page_number;
				

				if (cin.fail())
				{
					cout << "ERROR, Enter integer: \n";

					cin.clear();

					cin.ignore(numeric_limits<streamsize>::max(), '\n');

					cin >> page_number;

				}

			} while (cin.fail());

			cout << "\n";

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
		else if (choice == 5)
		{
			string bookToEdit;
			cin.ignore();
			cout << "Enter the title of the book you want to edit: ";
			getline(cin, bookToEdit);

			cout << "Enter new Author: ";
			getline(cin, author);

			cout << "Enter new Genre: ";
			getline(cin, genre);
			cout << "Enter new Release Date: ";
			cin >> release_date;

			cout << "Enter new Page Number: ";
			cin >> page_number;
			cout << endl;

			if (library.EditBook(bookToEdit, author, genre, release_date, page_number))
			{
				cout << "Book details updated successfully." << endl;
			}
			else
			{
				cout << "Book not found. Cannot edit." << endl;
			}
			choice = 0;
		}
	}

	return 0;

	}



	}





}