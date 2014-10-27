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
	fstream file;
public:
	FileReader(string name);
	void lineReplace(int l_number);
	void deleteLine(int l_number);
	void paragraphReplace(int p_number);
	void deleteParagraph(int p_number);
	int lineCount();
	int paragraphCount();
	~FileReader();
	void fileRead();
};

