#pragma once
#include <iostream>
#include "MyMenu.h"
#include <string>
#include "Editor.h"
#include "FileReader.h"
#include <locale>


class FileManager
{
public:
	FileManager();
	void openFile();
	void createFile();
	void menu();
	~FileManager();
	void loading();
	void copyFile();
	void openreadme();
	bool fileExist(string name) const;
	string toUpper(string word);
};

