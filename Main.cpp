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
        cout << "2. Search for a book by title" << endl;
        cout << "3. Search for books by genre" << endl;
        cout << "4. Print all book titles" << endl;
        cout << "5. Delete a book" << endl;
        cout << "6. Edit a book" << endl;
        cout << "7. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 7)
            break;


        switch (choice) {

        case 1:

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
            break;

        case 2:
            cout << "Enter a book title to search: ";
            getline(cin, title);

            library.printBookInfo(title);
            break;

        case 3:
            cout << "Enter a genre to search: ";
            getline(cin, genre);

            library.searchBooksByGenreInput();
            break;

        case 4:
            if (library.isEmpty()) {
                cout << "No books found." << endl;
            }
            else {
                library.printAllBooks();
            }
            break;

        case 5:
            cout << "Enter the title of the book you want to delete: ";
            getline(cin, title);
            if (library.DeleteBook(title)) {
                cout << "Book deleted" << endl;
            }
            else {
                cout << "Book not found." << endl;
            }
            break;

        case 6:
            cout << "Enter the title of the book you want to edit: ";
            cin.ignore();
            getline(cin, title);

            if (library.FindBook(title)) {
                cout << "Enter new Author: ";
                getline(cin, author);

                cout << "Enter new Genre: ";
                getline(cin, genre);

                do {
                    cout << "Enter new Release Year: ";
                    cin >> release_date;
                    if (cin.fail()) {
                        cout << "ERROR: Enter a valid integer." << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                } while (cin.fail());

                if (library.EditBook(title, author, genre, release_date, page_number)) {
                    cout << "Book updated successfully." << endl;
                }
                else {
                    cout << "Failed to update book details. " << endl;
                }
            }
            else {
                cout << "Book not found. Cannot edit." << endl;
            }
            break;
        default: cout << "Invalid choice. Please select a given option." << endl;

        }

    }
    cout << "End!" << endl;
    return 0;
}
