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
	Editor(string name);
	Editor(char*name, int);
	void editFile();
	void clearFile();
	void editLine();
	void deleteLine();
	void editParagraph();
	void deleteParagraph();
	void menu();
	~Editor();
};

