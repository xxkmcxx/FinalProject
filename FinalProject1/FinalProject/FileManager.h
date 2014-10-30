#pragma once
#include <iostream>
#include "MyMenu.h"
#include <string>
#include "Editor.h"
#include "FileReader.h"
#include <locale>


class FileManager
{
private:
	static string toUpper(string word);
	FileManager();
	~FileManager();
	static bool fileExist(string name);
public:

	static void openFile();
	static void createFile();
	static void menu();
	static void loading();
	static void copyFile();
	static void openreadme();
	
	
};

