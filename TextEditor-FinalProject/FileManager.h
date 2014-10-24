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
	MyString count[];

public:
	FileManager();
	~FileManager();
	void openFile();
	void createFile();
	void copyDocument();
	void showMenu();
};