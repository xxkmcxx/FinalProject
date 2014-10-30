#include <iostream>
#include "Editor.h"
#include "FileManager.h"
#include <fstream>
#include "FileReader.h"
using namespace std;

int main()
{
	FileManager fm;
	FileReader fr("sebi");

	fr.addLine(3);
	return(0);
}