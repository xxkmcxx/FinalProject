#pragma once
#include <iostream>
#include <fstream>
#include "MyMenu.h"
#include "EditorManager.h"
#include <string>

const int MAX_FILES = 10;

using namespace std;
class FileManager
{
private:
//Class instance variables
	fstream * file;
	string * FileName; //Guarda el nombre del file.

public:
	FileManager();
	~FileManager();
	string fixName(string FileName); //A~ade .txt al nombre del file
	void getName() const;
	void openFile();
	void createFile();
	void copyDocument();
	void showMenu();
};