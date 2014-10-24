
#include "FileManager.h"
FileManager::FileManager(fstream *file, string FileName)
{
}
FileManager::~FileManager()
{
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
	this->fileName[count] = fName
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
void FileManager::openFile()
{
	
}
void FileManager::createFile()
{
	cout << "Enter the name of the file" << endl;
}
void FileManager::copyDocument()
{

}

string FileManager::fixName(string FileName)
{
	FileName += ".txt";
	return FileName;
}