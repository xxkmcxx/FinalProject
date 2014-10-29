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
	FileReader fr("kevin.txt");
	cout << fr.paragraphCount() << endl;
	fm.menu();
	return(0);
}