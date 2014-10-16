#pragma once
#include <iostream>
#include <fstream>
#include "ListaDeCadenas.h"
using namespace std;

const int MAX_FILE = 10;
const int MAX_SENT = 100;

class FileManager
{
private:
	fstream file;
	ListaDeCadenas sentence;
	int quantity;
public:
	FileManager();
	FileManager();
	~FileManager();
	void openFile();
	void closeFile();
	void newFile();
};

