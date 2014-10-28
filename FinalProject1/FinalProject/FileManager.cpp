#define _WIN32_WINNT 0x0501
#include <SDKDDKVer.h>
#define WIN32_LEAN_AND_MEAN
#include <d3d9.h>
#include "FileManager.h"
#include <stdio.h>
#include <Windows.h>

FileManager::FileManager()
{
}


FileManager::~FileManager()
{
}

void FileManager::menu()
{
		MyMenu menu;
		int option;
		menu.cambiarTitulo("File Manager Menu                           |");
		menu.agregarOpcion("User Manual for Editor            |");
		menu.agregarOpcion("Create a new File                 |");
		menu.agregarOpcion("Open an existing File             |");
		menu.agregarOpcion("Clone File to new File            |");
		menu.agregarOpcion("Exit                              |");
		menu.cambiarPregunta("Please choose one of the option shown above.|");
		

		cout << "____________________________________________" << endl;
		cout << menu << endl;
		cout << "____________________________________________" << endl;
		cin >> option;
		if (option == 1)
		{
			this->openreadme();
			this->menu();
		}
		else if (option == 2)
		{
			this->createFile();
			this->menu();
		}
		else if (option == 3)
		{
			this->openFile();
			this->menu();
		}
		else if (option == 4)
		{
			this->copyFile();
			this->menu();
		}
		else if (option == 5)
		{
			cout << "Thank you,Bye!" << endl;
			return;
		}
		else
		{
			cout << "\aInvalid input, please try again" << endl;
			this->menu();
		}
}

int FileManager::openFile()
{
	string name;
	cout << "Enter the name of the file to open: ";
	cin >> name;
	name.append(".txt");
	FileReader emp(name);
	if (emp.is_empty(name))
	{
		cout << "File is empty." << endl;
	}
	else
	{
		cout << "This is what the file has currently written" << endl << endl;
	}
	FileReader read(name);
	read.fileRead();
	fstream file;
		if(file.fail())
		{
			cout << "\aFile with the name of " << name << " does not exist" << endl;
				return (0);
		}
		else
		{
			file.close();
			Editor edit(name);
			edit.menu();
			
		}
		
		return(0);
}

void FileManager::createFile()
{
	string name;
	cout << "Enter the name of the new file: ";
	cin >> name;
	name.append(".txt");
	cout << "Creating File..." << endl;
	this->loading();
	cout << "\aFile creation was succeful!" << endl;
	fstream file;
	if (file.fail())
	{
		cout << "\aWhoops! The file is missing." << endl;
	}
	else
	{
		file.close();
		Editor edit(name);
		edit.menu();
	}

}

void FileManager::copyFile()
{
	string source, destination, content;
	FileReader emp(source);
	do
	{
		cout << "Enter the name of the source file: ";
		cin >> source;
		source.append(".txt");
		if (emp.is_empty(source))
		{
			cout << "\aThis file is empty. Try a file with something on it.\n";
		}
	} while (emp.is_empty(source));


	fstream file(source);
	
	while (!file.eof())
	{
		getline(file, content, '-');
	}

	if (file.fail())
	{
		cout << "\aFile with the name of " << source << " does not exist" << endl;
	}
	else
	{
		cout << "Enter the name of the destination file: ";
		cin >> destination;
		destination.append(".txt");
		ofstream file2(destination);
		fstream file3(destination);
		if (file3.is_open())
		{
			file3 << content;
			this->loading();
			cout << "\aFile Cloning Completed." << endl << "You are editing " << destination << endl;
		}
		file.close();
		if (file3.is_open())
		{
			file3.close();
			Editor edit(destination);
			edit.menu();
		}
		else
		{
			cout << "\aWhoops! You broke something. Try Again!" << endl;
		}
	}
}

void FileManager::loading()
{
	double progress = 0.0;
	while (progress <= 1.0) 
	{
		int barWidth = 55;

		cout << "[";
		int pos = barWidth * progress;
		for (int i = 0; i <= barWidth; ++i) {
			if (i < pos) cout << "=";
			else if (i == pos) cout << ">";
			else cout << " ";
			Sleep(1);
		}
		cout << "] " << int(progress * 100.1) << " %\r";
		cout.flush();

		progress += 0.10;
	}
	cout <<endl;
}

void FileManager::openreadme(){

	ifstream file;

	cout << "Instructions for the program:" << endl;
	cout << endl;
	FileReader fr("readme.txt");
	fr.fileRead();

}

void FileManager::RecentFiles()
{
	fstream file("Recent Files.txt");
	string line;
	file.open("Recent Files.txt");
	if (file.is_open())
	{
		if (file.is_open())
		{
			while (getline(file, line))
			{
				cout << line << '\n';
			}

			file.close();
		}
		else cout << "\aUnable to open file";

	}
}