
#pragma once
#include<string>
#include "Node.h"
#include <iostream>
#include <cctype>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;



class LibraryTrie
{
private:

	Node* root;

	//This is the new index for ASCII characters instead of just lowercase 
	int getCharIndex(char c)
	{
		if (c >= 32 && c <= 126)
		{
			return c - 32;
		}
		return -1;  //if outside range
	}

	void searchBooksByGenre(Node* node, const string& genre, const string& currentTitle, vector<string>& results) const
	{
		if (node->endOfWord && node->genre == genre)
		{
			results.push_back(currentTitle);
		}
		for (int i = 0; i < 95; ++i)
		{
			if (node->children[i] != nullptr)
			{
				searchBooksByGenre(node->children[i], genre, currentTitle + char(i + 32), results);

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


		for (char c : title)
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


	}


	bool FindBook(const string& title)
	{

		Node* p = root;

		for (char c : title)
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

	

	void searchBooksByGenreInput() const 
	{
		cout << "Enter a genre to search: ";
		string genre;
		getline(cin, genre);
		vector<string> results;
		searchBooksByGenre(root, genre, "", results);
		if (!results.empty()) {
			cout << "Books in the genre \"" << genre << "\":" << endl;
			for (const string& title : results)
			{
				cout << "- " << title << endl;
			}
		}
		else {
			cout << "No books found in the genre \"" << genre << "\"." << endl;
		}
	}

	void printBookInfo(const string& title)
	{
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
			cout << "Title: " << title << std::endl;
			cout << "Author: " << p->author << std::endl;
			cout << "Genre: " << p->genre << std::endl;
			cout << "Year: " << p->year << std::endl;
			cout << "Page Number: " << p->pageNumber << std::endl;
		}
		else {
			cout << "Book not found." << std::endl;
		}

	}

	bool isEmpty()const
	{
		for (int i = 0; i < 95; i++)
		{
			if (root->children[i] != nullptr)
				return false;
		}
		return true;
	}

	void printAllBooks(Node* node, string prefix) const
	{
		if (node->endOfWord) {
			cout << prefix << endl;
		}
		for (int i = 0; i < 95; i++) {
			if (node->children[i])
			{
				printAllBooks(node->children[i], prefix + char(i + 32));
			}
		}
	}

	void printAllBooks() const { printAllBooks(root, ""); }

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

			cout << "Book details updated successfully." << endl;
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

		outfile.open("library.txt", std::ofstream::out | std::ofstream::trunc);
		outfile.close();


		outfile.open("Library.txt", std::ios::app);

		if (node->endOfWord) {
			outfile << prefix << endl;
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
