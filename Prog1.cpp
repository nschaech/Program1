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
	Timer timer;
	int compare = 0;
	int nondict = 0;
	int indict = 0;


	
	opentext.open("dict.txt");
	if (opentext.is_open())
	{
		opentext >> dict;
		while (!opentext.eof()){

			cleanWord(dict);
			dictlist.insert(dict);
			opentext >> dict;
		} 
		cout << dictlist.getSize() << endl;
	}
	opentext.close();
	cout << dictlist.getSize() <<"I am done with the dict"<< endl;

	opentext.open("book.txt");
	if (opentext.is_open())
	{
		opentext >> book;
		while (!opentext.eof()) {

			cout << book << endl;
			cleanWord(book);
			if (book.length() > 0)
			{
				compare++;
				if (dictlist.find(book))
				{
					indict++;
				}
				else {
					nondict++;
				}
			}
			opentext >> book;
		}
	}
	opentext.close();

	cout << "compares: " << compare << endl << "word not in dict: " << nondict << "words in dict: " << indict << endl;
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
		}
		else {
			word.erase(i,i+1);  //i,1
			i--;
		}
	}
}