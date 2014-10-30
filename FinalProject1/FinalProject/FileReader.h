#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class FileReader
{
private:
	string f_name;
	fstream file;
public:

	FileReader(string name);
	//replace methods-----------------------
	void wordReplace(string word, int occurrence);
	void lineReplace(int l_number);
	void sentenceReplace(int s_number);
	void paragraphReplace(int p_number);
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
	//---------------------------------
	//Add methots----------------------
	void addWord();
	void addSentence();	
	void addLine(int l_number);
	void addParagraph();
	//---------------------------------
	~FileReader();
	void fileRead();
	bool is_empty(string f_name);
	void editByLine(int l_number);
};

