#include <iostream>
#include "Editor.h"
#include "FileManager.h"
#include <fstream>
#include "FileReader.h"
#include <string>
#include <thread>

using namespace std;
void test()
{
	FileManager fr;
	fr.playsong();
}
int main()
{

	FileManager fm, fr;

	thread tests(test);
	fm.menu();

	return(0);
}