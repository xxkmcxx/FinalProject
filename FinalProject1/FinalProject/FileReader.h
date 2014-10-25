#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class FileReader
{
private:
	string f_name;
public:
	FileReader(string name);
	~FileReader();
	void fileRead();
	int ParagraphCount();
};

