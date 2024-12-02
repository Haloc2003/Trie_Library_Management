#pragma once
#include<string>
using namespace std;


class Node
{

public:
	Node* children[95];			
	bool endOfWord;
	int pageNumber;
	string author;
	string genre;
	int year;
	int book_number;
	string originalTitle; //keep the original title


	Node()
	{
		endOfWord = false;
		

		for (int i = 0; i < 95; i++)
		{
			children[i] = NULL;				
		}

		author = "";
		genre = "";
		year = 0;
		pageNumber = 0;
		originalTitle = "";
		
	}

};
