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
	for (int i = 0; i < MAX_FILES; i++)
	{
		this->FileName[i] = "";
	}
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
	void askName();
	cout << "Creating File...";
	void loadbar();
	ofstream file(FileName[g]);
	void RecentDocumentsSave();
	cout << "File Creation Complete.";
}

void FileManager::openFile(int &g)
{
	fstream file;
	nameCount(g);
}

void FileManager::askName()
{
	int g;
	cout << "Enter the name of the document: ";
	int nameCount();
	g = nameCount();
	cin >> FileName[g];
	void fixName();
	void openFile();
}

void FileManager::Menu()
{
	MyMenu menu;
	int option;
	menu.cambiarTitulo("File Manager Menu                           |");
	menu.agregarOpcion("Create a new File                 |");
	menu.agregarOpcion("Open an existing File             |");
	menu.agregarOpcion("Exit                              |");
	menu.cambiarPregunta("Please choose one of the option shown above.|");


	cout << "____________________________________________" << endl;
	cout << menu << endl;
	cout << "____________________________________________" << endl;
	cin >> option;
	if (option == 1)
	{
		void createFile();
		void menu();
	}
	else if (option == 2)
	{
		//openExistingFile();
		void menu();
	}
	else if (option == 3)
	{
		cout << "Thank you,Bye!" << endl;
		exit();
	}
	else
	{
		cout << "Invalid input, please try again" << endl;
		void menu();
	}

}

void FileManager::copyDocument(int &g)
{
	fstream file("Recent Files.txt"), file1;
	string recent, source, destination;
	cout << "Enter the name of the source file: ";
	nameCount(g);
	cin >> this->FileName[g];
	fixName(g);
	source = this->FileName[g];
	if (file.is_open())
	{
		while (getline(file, recent))
		{
			cout << recent << '\n';
		}
		file.close();
	}
	else cout << "Unable to open file";
	cout << "Enter the name of the destination file: ";
	nameCount(g);
	cin >> this->FileName[g];
	fixName(g);
	destination = this->FileName[g];
}

string FileManager::fixName(int &g)
{
	this->FileName[g].append(".txt");
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
		this->FileName[i].append("\n");
		Name = this->FileName[i];
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

inline void FileManager::loadbar(unsigned int &x, unsigned int &n, unsigned int &w)
{
	w = 50;
	if ((x != n) && (x % (n / 100 + 1) != 0)) return;

	double ratio = x / n;
	double   c = ratio * w;

	cout << setw(3) << (int)(ratio * 100) << "% [";
	for (x = 0; x<c; x++) cout << "=";
	for (x = c; x < w; x++) cout << " ";
	cout << "]\r" << flush;
}