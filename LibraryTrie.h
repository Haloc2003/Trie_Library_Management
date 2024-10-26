//
//I had a skeleton of the basic trie but it was really basic and I just needed to restart, not sure if im doing this right
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


	bool FindBook(const string* title)
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





};
