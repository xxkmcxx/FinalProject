#include "MyString.h"
#include "FileManager.h"
#include <string>
#include <string.h>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

FileManager::FileManager(string FileName)
{
	(*this) = FileName;
}

FileManager::FileManager(const FileManager & aFileManager)
{
	(*this) = aFileManager;
}

FileManager::~FileManager()
{
}

//This is the menu that will display the FileManager
void FileManager::createFile(int &g, unsigned int &x, unsigned int &n, unsigned int &w)
{
	askName(g);
	cout << "Creating File...";
	loadbar(x, n, w);
	cout << "File Creation Complete.";
}
void FileManager::openFile(int &g)
{
	fstream file;
	nameCount(g);
}

void FileManager::askName(int &g)
{
	cout << "Enter the name of the document: ";
	nameCount(g);
	cin >> this->FileName[g];
	fixName(g);
}

void FileManager::showMenu()
{
	MyMenu menu;
	int option;
	menu.cambiarTitulo("File Manager Menu");
	menu.agregarOpcion("Create a new File");
	menu.agregarOpcion("Open an existing File");
	menu.agregarOpcion("Copy an existing File");  //not sure if this option is needed
	menu.agregarOpcion("Exit");
	menu.cambiarPregunta("Please choose one of the option shown above.");
	do
	{
		switch (option)
		{
		case 1:
			void createFile();
		case 2:
			void openFile();
		case 3:
			void copyFile();
		case 4:
			int exit();
		case 5:
		default:
			cout << "Invalid input. Please try again." << endl;
		}
	} while (option != 4 || option != 5);
}

void FileManager::copyDocument()
{
	string source, destination;
	int i = 0, j = 0, g = 0;
}

string FileManager::fixName(int &g)
{
	this->FileName[g] += ".txt";
	return this->FileName[g];
}

int FileManager::nameCount(int &g)
{
	for (int i = 0; i < MAX_FILES; i++)
	{
		if (this->FileName[i] == "")
		{
			i = g;
		}
	}
	return g;
}

void FileManager::RecentDocumentsSave()
{
	fstream file;
	string Name = "", 
		   files = "";

	file.open("Recent Files.txt");

	while (getline(file, files))
	{
		getline(cin, files);
		cout << endl;
	}	

	for (int i = 0; i < (MAX_FILES) && file.is_open(); i++)
	{
		Name = FileName[i] + '\n';
	}		
	files = files + Name;
	getline(cin, Name, '\n');
	cin.ignore();
	file.close();
}

int FileManager::exit()
{
	return 0;
}

static inline void loadbar(unsigned int &x, unsigned int &n, unsigned int &w)
{
	w = 50;
	if ((x != n) && (x % (n / 100 + 1) != 0)) return;

	float ratio = x / (float)n;
	int   c = ratio * w;

	cout << setw(3) << (int)(ratio * 100) << "% [";
	for (int x = 0; x<c; x++) cout << "=";
	for (int x = c; x<w; x++) cout << " ";
	cout << "]\r" << flush;
}