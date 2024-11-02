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
        cout << "Library Menu:" << endl;
        cout << "1. Add a new book" << endl;
        cout << "2. Search for a book" << endl;
        cout << "3. Print all book titles" << endl;
        cout << "4. Delete a book" << endl;
        cout << "5. Edit a book" << endl;
        cout << "6. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 6)
            break;

        if (choice == 1)
        {
            cin.ignore();
            cout << "Enter Title: ";
            getline(cin, title);

            cout << "Enter Author: ";
            getline(cin, author);

            cout << "Enter Genre: ";
            getline(cin, genre);

            do
            {
                cout << "Enter Release Year: ";
                cin >> release_date;

                if (cin.fail())
                {
                    cout << "ERROR: Enter a valid integer." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            } while (cin.fail());

            do
            {
                cout << "Enter Page Number: ";
                cin >> page_number;

                if (cin.fail())
                {
                    cout << "ERROR: Enter a valid integer." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            } while (cin.fail());

            cout << endl;
            library.NewBook(title, author, genre, release_date, page_number);
        }
        else if (choice == 2)
        {
            string searchTitle;
            cin.ignore();
            cout << "Enter a book title to search: ";
            getline(cin, searchTitle);

            library.printBookInfo(searchTitle);
            cout << endl;
        }
        else if (choice == 3)
        {
            if (library.isEmpty())
            {
                cout << "No books found." << endl;
            }
            else
            {
                library.printAllBooks();
            }
            cout << endl;
        }
        else if (choice == 4)
        {
            string bookToDelete;
            cin.ignore();
            cout << "Enter the title of the book you want to delete: ";
            getline(cin, bookToDelete);

            if (library.DeleteBook(bookToDelete))
            {
                cout << "Book deleted." << endl;
            }
            else
            {
                cout << "Book not found." << endl;
            }
            cout << endl;
        }
        else if (choice == 5)
        {
            string bookToEdit;
            cin.ignore();
            cout << "Enter the title of the book you want to edit: ";
            getline(cin, bookToEdit);

            if (library.FindBook(bookToEdit))
            {
                cout << "Enter new Author: ";
                getline(cin, author);

                cout << "Enter new Genre: ";
                getline(cin, genre);

                do
                {
                    cout << "Enter new Release Year: ";
                    cin >> release_date;

                    if (cin.fail())
                    {
                        cout << "ERROR: Enter a valid integer." << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                } while (cin.fail());

                do
                {
                    cout << "Enter new Page Number: ";
                    cin >> page_number;

                    if (cin.fail())
                    {
                        cout << "ERROR: Enter a valid integer." << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                } while (cin.fail());

                cout << endl;

                if (library.EditBook(bookToEdit, author, genre, release_date, page_number))
                {
                    cout << "Book details updated successfully." << endl;
                }
                else
                {
                    cout << "Failed to update book details." << endl;
                }
            }
            else
            {
                cout << "Book not found. Cannot edit." << endl;
            }
            cout << endl;
        }
        else
        {
            cout << "Invalid choice. Please select a valid option." << endl;
        }
    }

    return 0;




}