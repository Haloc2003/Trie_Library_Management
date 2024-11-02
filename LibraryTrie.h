
#pragma once
#include<string>
#include "Node.h"
#include<iostream>
#include<cctype>
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
};
