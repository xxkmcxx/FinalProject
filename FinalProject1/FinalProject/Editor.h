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
public:
	Editor(string name);
	Editor(char*name, int);
	void editFile();
	void clearFile(fstream &file);
	void readFile(string name);
	void menu();
	~Editor();
};

