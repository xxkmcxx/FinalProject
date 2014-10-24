#pragma once
#include <iostream>
#include <fstream>
#include "MyMenu.h"
#include "EditorManager.h"
#include "MyString.h"
#include "Editor.h"

using namespace std;

class FileManager
{
private:
//Class instance variables
	fstream file;
	string FileName; //Guarda el nombre del file.

public:
	FileManager(fstream *file, string FileName);
	FileManager(const FileManager & aFileManager);
	~FileManager();
	string fixName(string FileName); //A~ade .txt al nombre del file
	void getName() const;
	void openFile();
	void createFile();
	void copyDocument(const FileManager & aFileManager, string FileName[MAX_FILES]);
	bool operator == (const FileManager & aFileManager) const;
	bool operator == (string FileName[MAX_FILES]) const;
	void showMenu();
};