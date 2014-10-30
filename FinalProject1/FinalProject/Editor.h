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
	FileReader reader;
	bool isempty();
public:
	Editor(string name);
	Editor(char*name, int);
	~Editor();

	//Edit Methots------------
	void editFile();
	void editLine();
	void editParagraph();
	void editWord();
	void editSentence();
	//------------------------

	//Delete Methots----------
	void deleteLine();
	void deleteParagraph();
	void deleteWord();
	void deleteSentence();
	void clearFile();
	//------------------------

	//Replace Methots---------
	void replaceLine();
	void replaceParagraph();
	void replaceWord();
	void replaceSentence();
	//------------------------

	//Add Methots-------------
	void addLine();
	void addWord();
	//------------------------

	void menu();
};

