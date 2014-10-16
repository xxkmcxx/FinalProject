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
	EditorManager eManager;

public:
	FileManager();
	~FileManager();
	static void openFile();
	static void createFile();
	static void copyDocument();
	static void showMenu();
};