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

    //Establishes a library from a text file
    library.ImportFromFile("BackgroundLibrary.txt");

    //Menu
    while (choice != 9)
    {
        cout << "Library Menu:" << endl;
        cout << "1. Add a new book" << endl;
        cout << "2. Search for a book" << endl;
        cout << "3. Print all book titles" << endl;
        cout << "4. Delete a book" << endl;
        cout << "5. Print a single book to a file." << endl;
        cout << "6. Print library to to a file." << endl;
        cout << "7. Import a book from a file." << endl;
        cout << "8. Edit a book" << endl;
        cout << "9. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 9)
            break;

        //Add Book Option
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

        //Searching Options
        else if (choice == 2)
        {

            system("cls");

            int search_choice = 0;
            cout << "1. Search by Title"
                << "\n2. Search by Genre"
                << "\n3. Search by Author";
            

            while (search_choice != 1 && search_choice != 2 && search_choice != 3)
            {
                cout << "\nEnter Choice: ";
                cin >> search_choice;

                if (search_choice == 1)
                {
                    /*
                    string searchTitle;
                    cin.ignore();
                    cout << "\nEnter a book title to search: ";
                    getline(cin, searchTitle);
                    library.printBookInfo(searchTitle);
                    cout << endl;
                    */

                    cin.ignore();
                    library.searchBooksByTitleInput();

                }

                else if (search_choice == 2)
                {   
                    cin.ignore();
                    library.searchBooksByGenreInput();
                }

                else if (search_choice == 3)
                {
                    cin.ignore();
                    library.searchBooksByAuthorInput();
                }

                else if (search_choice != 1 && search_choice != 2 && search_choice != 3)
                {
                    cout << "Error: Not a choice.";
                }
            }
        }

        //Displaying Books Option
        else if (choice == 3)
        {
            if (library.isEmpty())
            {
                cout << "No books found." << endl;
            }
            else
            {
                cout << endl;
                library.printAllBooks();
            }
            cout << endl;
        }

        //Deleting Book Option
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
        if (choice == 5)
        {
            string searchTitle;
            cin.ignore();
            cout << "Enter a book title to search: ";
            getline(cin, searchTitle);

            library.PrintBookInfoToFile(searchTitle);
            cout << "Printed to File" << endl;


        }

        //Printing all books to file option
        if (choice == 6)
        {

            if (library.isEmpty())
            {
                cout << "No books found. " << endl;
            }
            else
            {
                fstream outfile;

                outfile.open("library.txt", std::ofstream::out | std::ofstream::trunc);
                outfile.close();

                library.PrintAllToFile();
                cout << "Printed to File" << endl;
            }

        }

        //Importing a book from a file option
        if (choice == 7)
        {
            string filename;

            cout << "Enter File Name (include .txt at the end): ";
            cin.ignore();
            getline(cin, filename);
            library.ImportFromFile(filename);

            cout << "File imported.\n";
        }

        //Edit a book option
        else if (choice == 8)
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
        else if (choice != 9 && choice != 8 && choice != 7 && choice != 6 && choice != 5 && choice != 4 && choice != 3 && choice != 2 && choice != 1 )
        {
            cout << "Invalid choice. Please select a valid option." << endl;

        }

        system("pause");
        system("cls");

    }

    return 0;




}