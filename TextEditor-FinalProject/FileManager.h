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
	fstream file;

public:
	FileManager();
	~FileManager();
	static void openFile();
	static void createFile();
	static void copyDocument();
	static void showMenu();
};