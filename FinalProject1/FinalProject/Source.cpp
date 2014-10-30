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

	fr.editByLine(2);
	fr.lineReplace(2);



	fr.addLine(3);
	return(0);
}