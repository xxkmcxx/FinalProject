#include <iostream>
#include "Editor.h"
#include "FileManager.h"
#include <fstream>
#include "FileReader.h"
#include <string>
#include <thread>
using namespace std;

int main()
{
	FileManager fm;
	FileReader fr("sebi.txt");
	fr.addLine(3);
	return(0);
}