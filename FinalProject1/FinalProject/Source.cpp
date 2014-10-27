#include <iostream>
#include "Editor.h"
#include "FileManager.h"
#include <fstream>
#include "FileReader.h"
#include <string>

using namespace std;

int main()
{

	FileManager fm;
	FileReader fr("Kevin.txt");

	cout << fr.paragraphCount() << endl;
	cout << fr.lineCount() << endl;

	fm.menu();

	return(0);
}