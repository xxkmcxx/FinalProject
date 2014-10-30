#include <iostream>
#include "Editor.h"
#include "FileManager.h"
#include <fstream>
#include <string>
#include "FileReader.h"
using namespace std;

int main()
{

	FileReader fr("Kevin.txt");
	FileManager::menu();
	return(0);
}