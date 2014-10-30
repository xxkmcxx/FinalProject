#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <Windows.h>
#include <string>
#include <ctype.h>

using namespace std;

class FileReader
{
private:
	string f_name;
	fstream file;
public:

	FileReader(string name);
	~FileReader();

	//replace methods-----------------------
	void wordReplace(string word, int occurrence);
	void lineReplace(int l_number);
	void sentenceReplace(int s_number);
	void paragraphReplace(int p_number);
	void editByLine(int l_number); //Adds a line to the text file without deleting text.
	//--------------------------------------

	//delete methods-----------------------
	void wordDelete(string word, int occurrence);
	void deleteLine(int l_number);
	void deleteSentence(int s_number);
	void deleteParagraph(int p_number);
	//------------------------------------

	//count methods-------------------
	int lineCount();
	int paragraphCount();
	int sentenceCount();
	int wordCount();
	int wordCount(string word);
	void wordPosCount(size_t remote_variable, string word_to_find, string file_content_holder); //Looks and print position of a word.
	//---------------------------------

	//Utility--------------------------
	void fileRead();
	bool is_empty(string f_name);
	//---------------------------------
};

