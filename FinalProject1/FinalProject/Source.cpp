#include <iostream>
#include "Editor.h"
#include "FileManager.h"
#include <fstream>
#include <string>
#include "FileReader.h"
using namespace std;

int main()
{
	FileManager fm;
	FileReader fr("Kevin.txt");

	fm.menu();
	return(0);
}