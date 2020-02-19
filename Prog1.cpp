#include "timer.h"
#include "NODE.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

void cleanWord(string& word);

int main()
{
	ifstream opentext;
	ofstream returntext;
	string book, dict;
	myList<string> dictlist;


	
	opentext.open("dict.txt");
	if (opentext.is_open())
	{
		while (!opentext.eof())
		{
			opentext >> dict;
			//clean the word
			cleanWord(dict);
			if (dict.length() != 0)
			{
				dictlist.insert(dict);
			}

		}
	}
	opentext.close();

	opentext.open("book.txt");
	if (opentext.is_open())
	{
		while (!opentext.eof())
		{
			opentext >> book;
			cleanWord(book);

		}
	}
	opentext.close();
	return 0;
}

void cleanWord(string& word)
{
	int len = word.length();
	for (int i = 0; i < len; i++)
	{
		char let = word.at(i);
		if (let == '\'') {
			i++;
		}
		else if (isalnum(let)) {
			if (isalpha(let))
			{
				word.at(i) = tolower(word.at(i));
			}
			else {
				i++;
			}
		}
		else {
			word.erase(word.begin() + i + 1);
		}
	}
}