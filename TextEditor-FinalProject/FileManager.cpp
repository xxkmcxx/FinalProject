#include "MyString.h"
#include "FileManager.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

FileManager::FileManager(string FileName[MAX_FILES])
{
	FileName[0] = "";
	FileName[1] = "";
	FileName[2] = "";
	FileName[3] = "";
	FileName[4] = "";
	FileName[5] = "";
	FileName[6] = "";
	FileName[7] = "";
	FileName[8] = "";
	FileName[9] = "";
}

FileManager::FileManager(const FileManager & aFileManager)
{
	(*this) = aFileManager;
}

FileManager::~FileManager()
{
}

void FileManager::setName(const FileManager & aFileManager)
{
	strcpy(this->FileName, MAX_LEN, aFileManager);
}

string FileManager::getName() const
{
	return(*this);
}

//This is the menu that will display the FileManager
void FileManager::createFile()
{
	MyString name;
	cout << "Insert a name for a file" << endl;
	cin >> name;
	
}
void FileManager::openFile()
{
	fstream *file;
	MyString fName;
	Editor editor(*file, fName);
	editor.menu();
	this->FileName[count] = fName
	this->fcount++;
}
void FileManager::copyDocument()
{

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

		case 5:
		default:
			cout << "Invalid input. Please try again." << endl;
		}
	} while (option != 4 || option != 5);
}

void FileManager::createFile()
{

}

void FileManager::copyDocument(string FileName)
{
	string source, destination;
	int i = 0, j = 0, g = 0;
}

string FileManager::fixName(string FileName[], int &g)
{
	nameCount(g);
	FileName[g] += ".txt";
	return FileName[g];
}

int FileManager::nameCount(int &g)
{
	for (int i = 0; i < MAX_FILES; i++)
	{
		if (FileName[i] == "")
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