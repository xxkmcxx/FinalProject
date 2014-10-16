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
// Constructors are made private because class methods are static.
	EditorManager eManager; 


public:
	FileManager();
	~FileManager();
	static void openFile();
	static void createFile();
	static void copyDocument();
	static void showMenu();
};