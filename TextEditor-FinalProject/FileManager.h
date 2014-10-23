#pragma once
#include <iostream>
#include <fstream>
#include "MyMenu.h"
#include "EditorManager.h"
#include <string>

using namespace std;
class FileManager
{
private:
//Class instance variables
	fstream file;

public:
	FileManager();
	~FileManager();
	void openFile();
	void createFile();
	void copyDocument();
	void showMenu();
};