
#include "FileManager.h"
FileManager::FileManager(fstream *file, string FileName)
{
	string FileName = "";
}
FileManager::~FileManager()
{
}
//This is the menu that will display the FileManager
void FileManager::showMenu()
{
	MyMenu menu;
	int option;
	menu.cambiarTitulo("File Manager Menu");
	menu.agregarOpcion("Create a new File");
	menu.agregarOpcion("Open an existing File");
	menu.agregarOpcion("Copy an existing File");
	menu.agregarOpcion("Exit manager and start editing a file"); //not sure if this option is needed
	menu.agregarOpcion("Exit");
	menu.cambiarPregunta("Please choose one of the option shown above.");
	do
	{
		switch (option)
		{
		case 1:
			void createFile();
			break;
		case 2:
			void openFile();
			break;
		case 3:
			void copyFile();
			break;
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

void FileManager::copyDocument(const FileManager & aFileManager, string FileName[MAX_FILES])
{
	string source, destination;
	int a = 0;
	cout << "Enter the name of the source file: ";
	cin >> source;
	cout << "Enter the name of the destination file: ";
	cin >> destination;
	for (int i = 0, int g = 0; g == 1 ; i++)
	{
		if (source == FileName[i])
		{
			FileName[i] = source;
			g++;
		}
	}
	for (int j = 0, g = 0; g == 1; j++)
	{
		if (FileName[j] == "")
		{
			FileName[j] = destination;
		}
	}
		ifstream file(source);

	char a[512];


	while (!source.eof())

	{
		source >> a;
	}


	ofstream aFileManager.FileName[i];
	file.open(destination);
	file << a;
	file.close();
}

bool FileManager::operator ==(const FileManager & aFileManager) const
{
	return(this->FileName == aFileManager.FileName);
}

bool FileManager::operator ==(string FileManager) const
{

}

string FileManager::fixName(string FileName)
{
	FileName += ".txt";
	return FileName;
}