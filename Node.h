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


	Node() : endOfWord(false), year(0), pageNumber(0), book_number(0) , author(""), genre(""){
		for (int i = 0; i < 95; i++) {
			children[i] = nullptr;
		}
	}
	

};
