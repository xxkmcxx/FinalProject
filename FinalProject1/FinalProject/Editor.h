#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
#include "MyMenu.h"
#include "FileReader.h"

using namespace std;

class Editor
{
private:
	string f_name;
	fstream file;
	bool isempty();
	FileReader reader;
public:
	Editor(const Editor & anEditor);
	Editor(string name);
	Editor(char*name, int);
	Editor & operator =(const Editor & anEditor);
	void editFile();
	void clearFile();
	void editLine();
	void deleteLine();
	void editParagraph();
	void deleteParagraph();
	void editWord();
	void deleteWord();
	void editSentence();
	void deleteSentence();
	void menu();
	~Editor();
};

