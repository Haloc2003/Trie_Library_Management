
#pragma once
#include<string>
#include "Node.h"
#include <iostream>
#include <cctype>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;


//heloper for converting string to lowercase
string toLowerCase(const string& input)
{
	string result = input;
	transform(result.begin(), result.end(), result.begin(), ::tolower);
	return result;
}


class LibraryTrie
{
private:

	Node* root;

	//This is the new index for ASCII characters instead of just lowercase 
	int getCharIndex(char c)
	{
		c = tolower(c);
		if (c >= 32 && c <= 126)
		{
			return c - 32;
		}
		return -1;  //if outside range

	}


	//Skeleton for Genre search
	void searchBooksByGenre(Node* node, const string& prefix, string currentGenre, vector<Node*>& results) const {
		if (node->endOfWord) 
		{
			string lowerGenre = toLowerCase(node->genre);
			string lowerPrefix = toLowerCase(prefix);

			
			if (lowerGenre.find(lowerPrefix) == 0) 
			{
				results.push_back(node); 
			}
		}

		for (int i = 0; i < 95; ++i) 
		{
			if (node->children[i] != nullptr) 
			{
				searchBooksByGenre(node->children[i], prefix, currentGenre + char(i + 32), results);
			}
		}
	}
	//Skeleton for Author search
	void searchBooksByAuthor(Node* node, const string& prefix, string currentAuthor, vector<Node*>& results) const 
	{
		if (node->endOfWord)
		{
			string lowerAuthor = toLowerCase(node->author);
			string lowerPrefix = toLowerCase(prefix);


			if (lowerAuthor.find(lowerPrefix) == 0) {
				results.push_back(node);
			}
		}

		for (int i = 0; i < 95; ++i)
		{
			if (node->children[i] != nullptr)
			{
				searchBooksByAuthor(node->children[i], prefix, currentAuthor + char(i + 32), results);
			}
		}
	}

	//Skeleton for Title search
	void searchBooksByTitle(Node* node, const string& prefix, string currentTitle, vector<Node*>& results) const
	{
		if (node->endOfWord)
		{
			string lowerTitle = toLowerCase(node->originalTitle);
			string lowerPrefix = toLowerCase(prefix);


			if (lowerTitle.find(lowerPrefix) == 0) {
				results.push_back(node);
			}
		}

		for (int i = 0; i < 95; ++i)
		{
			if (node->children[i] != nullptr)
			{
				searchBooksByTitle(node->children[i], prefix, currentTitle + char(i + 32), results);
			}
		}
	}


public:

	LibraryTrie()
	{
		root = new Node();
	}

	//insert title into trie
	void NewBook(const string& title, const string& author, const string& genre, int year, int pageNumber)  //added year, im not sure about reading level
	{

		Node* p = root;
		string lowerTitle = toLowerCase(title);

		for (char c : lowerTitle)
		{
			int index = getCharIndex(c);      //this has changed with the new function

			if (index == -1) continue;

			if (p->children[index] == nullptr)
			{
				p->children[index] = new Node();
			}

			p = p->children[index];

		}

		p->endOfWord = true;
		p->pageNumber = pageNumber;
		p->author = author;
		p->genre = genre;
		p->year = year;
		p->originalTitle = title;


	}

	//Finds Specific Book
	bool FindBook(const string& title)
	{

		Node* p = root;
		string lowerTitle = toLowerCase(title);

		for (char c : lowerTitle)
		{

			int index = getCharIndex(c);

			if (index == -1 || p->children[index] == nullptr)		//checking to see if title exists
			{
				return false;
			}
			p = p->children[index];

		}

		return p->endOfWord;

	}

	
	//searches for books by genre
	void searchBooksByGenreInput() const 
	{
		cout << "Enter the genre to search: ";
		string prefix;
		getline(cin, prefix);

		vector<Node*> results;
		searchBooksByGenre(root, prefix, "", results);

		if (!results.empty()) 
		{
			cout << "Results for \"" << prefix << "\":" << endl << endl;
			for (Node* node : results)
			{
				cout << "Title: " << node->originalTitle << endl;
				cout << "Author: " << node->author << endl;
				cout << "Genre: " << node->genre << endl;
				cout << "Year: " << node->year << endl;
				cout << "Page Number: " << node->pageNumber << endl;
				cout << "-----------------------------" << endl;

			}

		}
		else 
		{
			cout << "No books found in genres starting with \"" << prefix << "\"." << endl;
		}
	}

	//searches for books by author
	void searchBooksByAuthorInput() const 
	{
		cout << "Enter the author's name to search: ";
		string prefix;
		getline(cin, prefix);

		vector<Node*> results;
		searchBooksByAuthor(root, prefix, "", results);

		if (!results.empty()) 
		{
			cout << "Results for \"" << prefix << "\":" << endl << endl;
			for (Node* node : results)
			{
				cout << "Title: " << node->originalTitle << endl;
				cout << "Author: " << node->author << endl;
				cout << "Genre: " << node->genre << endl;
				cout << "Year: " << node->year << endl;
				cout << "Page Number: " << node->pageNumber << endl;
				cout << "-----------------------------" << endl;

			}

		}
		else 
		{
			cout << "No books found by authors starting with \"" << prefix << "\"." << endl;
		}
	}

	//searches for books by title
	void searchBooksByTitleInput() const
	{
		cout << "Enter the title: ";
		string prefix;
		getline(cin, prefix);

		vector<Node*> results;
		searchBooksByTitle(root, prefix, "", results);

		if (!results.empty())
		{
			cout << "Results for \"" << prefix << "\":" << endl << endl;
			for (Node* node : results)
			{
				cout << "Title: " << node->originalTitle << endl;
				cout << "Author: " << node->author << endl;
				cout << "Genre: " << node->genre << endl;
				cout << "Year: " << node->year << endl;
				cout << "Page Number: " << node->pageNumber << endl;
				cout << "-----------------------------" << endl;
				
			}

			
		}
		else
		{
			cout << "No books found by \"" << prefix << "\"." << endl;
		}
	}

	//Prints a single book's Information
	void printBookInfo(const string& title)
	{
		Node* p = root;

		string lowerTitle = toLowerCase(title);


		for (char c : lowerTitle)
		{
			int index = getCharIndex(c);
			if (index == -1 || p->children[index] == nullptr)
			{
				cout << "Book not found." << endl;
				return;
			}
			p = p->children[index];
		}

		if (p->endOfWord)
		{
			cout << "Title: " << p->originalTitle << std::endl;
			cout << "Author: " << p->author << std::endl;
			cout << "Genre: " << p->genre << std::endl;
			cout << "Year: " << p->year << std::endl;
			cout << "Page Number: " << p->pageNumber << std::endl;
		}
		else {
			cout << "Book not found." << std::endl;
		}

	}

	//Indicates Empty trie
	bool isEmpty()const
	{
		for (int i = 0; i < 95; i++)
		{
			if (root->children[i] != nullptr)
				return false;
		}
		return true;
	}

	//Displays all books
	void printAllBooks(Node* node, string prefix) const
	{
		if (node->endOfWord) {
			cout << node->originalTitle << endl;
		}
		for (int i = 0; i < 95; i++) {
			if (node->children[i])
			{
				printAllBooks(node->children[i], prefix + char(i + 32));
			}
		}
	}

	void printAllBooks() const { printAllBooks(root, ""); }

	//Deletes Book from Trie
	bool DeleteBook(string& title)
	{
		Node* currentNode = root;
		Node* lastBranchNode = nullptr;
		char lastBranchChar = '\0';

		for (auto c : title) {

			int index = getCharIndex(c);

			if (index == -1 || currentNode->children[index] == nullptr) {
				return false;
			}
			else {
				int count = 0;
				for (int i = 0; i < 95; i++) {
					if (currentNode->children[i] != nullptr)
						count++;
				}

				if (count > 1) {
					lastBranchNode = currentNode;
					lastBranchChar = c;
				}
				currentNode = currentNode->children[index];
			}
		}

		int count = 0;
		for (int i = 0; i < 95; i++) {
			if (currentNode->children[i] != nullptr)
				count++;
		}

		// Case 1: The deleted word is a prefix of other words
		// in Trie.
		if (count > 0)
		{
			currentNode->endOfWord = false;
			return true;
		}

		// Case 2: The deleted word shares a common prefix with
		// other words in Trie.

		if (lastBranchNode != nullptr) 
		{
			int lastBranchIndex = getCharIndex(lastBranchChar);
			delete lastBranchNode->children[lastBranchIndex];
			lastBranchNode->children[lastBranchIndex] = nullptr;
			return true;
		}
		// Case 3: The deleted word does not share any common
		// prefix with other words in Trie.
		else
		{
			int rootIndex = getCharIndex(title[0]);
			delete root->children[rootIndex];
			root->children[rootIndex] = nullptr;
			return true;
		}
	}

	//Edits specific titles contents
	bool EditBook(const string& title, const string& newAuthor, const string& newGenre, int newYear, int newPageNumber)
	{
		Node* p = root;

		for (char c : title)
		{
			int index = getCharIndex(c);
			if (index == -1 || p->children[index] == nullptr)
			{
				cout << "Book not found. Cannot edit." << endl;
				return false;
			}
			p = p->children[index];
		}

		if (p->endOfWord)
		{
			p->author = newAuthor;
			p->genre = newGenre;
			p->year = newYear;
			p->pageNumber = newPageNumber;

			return true;
		}
		else
		{
			cout << "Book not found. Cannot edit." << endl;
			return false;
		}
	}
	// Adds Book Information to a file
	void PrintBookInfoToFile(string& title)
	{
		fstream outfile;

		outfile.open("LibraryInfo.txt");

		Node* p = root;

		for (char c : title)
		{
			int index = getCharIndex(c);
			if (index == -1 || p->children[index] == nullptr)
			{
				cout << "Book not found." << endl;
				return;
			}
			p = p->children[index];
		}

		if (p->endOfWord)
		{
			outfile << title << std::endl;
			outfile << p->author << std::endl;
			outfile << p->genre << std::endl;
			outfile << p->year << std::endl;
			outfile << p->pageNumber << std::endl;
			outfile << std::endl;
		}
		else {
			cout << "Book not found." << std::endl;
		}

		outfile.close();

	}

	//Adds all current books to a file
	void PrintAllToFile(Node* node, string prefix) const
	{
		fstream outfile;

		outfile.open("Library.txt", std::ofstream::out | std::ios::app);

		if (node->endOfWord) {
			outfile << node->originalTitle << endl;
		}
		for (int i = 0; i < 95; i++) {
			if (node->children[i])
			{
				PrintAllToFile(node->children[i], prefix + char(i + 32));
			}
		}

		outfile.close();
	}

	void PrintAllToFile() const { PrintAllToFile(root, ""); }

	// Writes a book from a file to the trie
	void ImportFromFile(string filename)
	{
		string title, author, genre, line;
		int page_number, year;

		ifstream infile;
		infile.open(filename);

		while (getline(infile, title))
		{
			getline(infile, author);
			getline(infile, genre);
			getline(infile, line);
			year = atol(line.c_str());
			getline(infile, line);
			page_number = atol(line.c_str());
			getline(infile, line);

			NewBook(title, author, genre, year, page_number);


		}

		infile.close();
	}

};
