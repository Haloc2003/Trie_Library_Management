#pragma once
#include<string>
using namespace std;


class Node
{

public:
	Node* children[26];			
	bool endOfWord;
	int pageNumber;
	string author;
	string genre;
	int year;
	int book_number;


	Node()
	{
		endOfWord = false;
		pageNumber = -1;

		int year = -1;

		for (int i = 0; i < 26; i++)
		{
			children[i] = NULL;				
		}
	}

};
