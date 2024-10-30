//
//
//
#pragma once
#include<string>
#include "Node.h"
#include<iostream>
using namespace std;



class LibraryTrie
{
private:

	Node* root;

public:

	LibraryTrie()
	{
		root = new Node();
	}

	//insert title into trie
	void NewBook(const string* title, const string* author, const string* genre, int* year, int* pageNumber)  //added year, im not sure about reading level
	{

		Node* p = root;


		for (int i = 0; i < title->length(); i++)
		{

			char ch = tolower((*title)[i]);
			int index = ch - 'a';

			if (index < 0 || index >= 26)  //making sure in range
			{
				continue;
			}



			if (p->children[index] == nullptr)
			{
				p->children[index] = new Node();
			}

			p = p->children[index];

		}


		//dereferencing to get values

		p->endOfWord = true;
		p->pageNumber = *pageNumber;
		p->author = *author;
		p->genre = *genre;
		p->year = *year;


	}


	bool FindBook(Node* root, const string* title)
	{

		Node* p = root;

		for (int i = 0; i < title->length(); i++)
		{

			int index = tolower((*title)[i]) - 'a';

			if (p->children[index] == nullptr)		//checking to see if title exists
			{
				return false;
			}
			p = p->children[i];

		}

		if (p != nullptr && p->endOfWord)
		{

			cout << "Title: " << *title << endl;        // Dereferencee to print 
			cout << "Author: " << p->author << endl;
			cout << "Genre: " << p->genre << endl;
			cout << "Year: " << p->year << endl;
			cout << "Page Number: " << p->pageNumber << endl;
			return true;

		}

		return false; //if the title isnt found

	}

	
	bool DeleteBook(Node* root, string& title)
	{
		Node* currentNode = root;
		Node* lastBranchNode = NULL;
		char lastBranchChar = 'a';

		for (auto c : title) {
			if (currentNode->children[c - 'a'] == NULL) {
				return false;
			}
			else {
				int count = 0;
				for (int i = 0; i < 26; i++) {
					if (currentNode->children[i] != NULL)
						count++;
				}

				if (count > 1) {
					lastBranchNode = currentNode;
					lastBranchChar = c;
				}
				currentNode = currentNode->children[c - 'a'];
			}
		}

		int count = 0;
		for (int i = 0; i < 26; i++) {
			if (currentNode->children[i] != NULL)
				count++;
		}

		// Case 1: The deleted word is a prefix of other words
		// in Trie.
		if (count > 0) 
		{
			currentNode->book_number--;
			return true;
		}

		// Case 2: The deleted word shares a common prefix with
		// other words in Trie.
		if (lastBranchNode != NULL) 
		{
			lastBranchNode->children[lastBranchChar] = NULL;
			return true;
		}
		// Case 3: The deleted word does not share any common
		// prefix with other words in Trie.
		else 
		{
			root->children[title[0]] = NULL;
			return true;
		}
	}



};
