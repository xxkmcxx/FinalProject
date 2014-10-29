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
		string option;
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
		if (option == "1")
		{
			this->openreadme();
			this->menu();
		}
		else if (option == "2")
		{
			this->createFile();
			this->menu();
		}
		else if (option == "3")
		{
			this->openFile();
			this->menu();
		}
		else if (option == "4")
		{
			this->copyFile();
			this->menu();
		}
		else if (option == "5")
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

void FileManager::openFile()
{
	string name;
	cout << "Enter the name of the file to open: ";
	cin >> name;
	while (name == "readme.txt" || name == "recent.txt")
	{
		cout << "Oops... Those files are for read only choose another file to open" << endl;
		cin >> name;
	}
	name.append(".txt");
	ifstream file;
	file.open(name);
		while(file.fail())
		{
			cout << "\aFile with the name of " << name << " does not exist" << endl;
			cout << "Please try again." << endl;
			cout << "Enter the name of the file to open";
			cin >> name;
			name.append(".txt");
			file.close();
			file.open(name);
		}
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
			file.close();
			Editor edit(name);
			edit.menu();

}

void FileManager::createFile()
{
	string name;
	cout << "Enter the name of the new file: ";
	cin >> name;
	name.append(".txt");
	
	if (this->fileExist(name))
	{
		fstream file;
		file.open(name, ios::out);
	cout << "Creating File..." << endl;
	this->loading();
	cout << "\aFile creation was succeful!" << endl;
		file.close();
		Editor edit(name);
		edit.menu();
		this->menu();
	}
	else
	{
		string yn;
		cout << "\aWhoops! This file already exist." << endl;
		cout << "Do you want to open it instead? (Y/N): ";
		cin >> yn;
		do
		{
			if (yn == "Y" || yn == "y")
			{
				fstream file(name);
		Editor edit(name);
				file.open(name);
		edit.menu();
				this->menu();
	}
			else if (yn == "N" || yn == "n")
				this->menu();
			else
			{
				{
					cout << "\aDidn't get that. Try again. \n Y or N? ";
					cin >> yn;
}
			}
		} while (yn != "y" || yn != "Y" || yn != "n" || yn != "N");
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
		if (this->fileExist(source))
		{
			cout << "This file does not exist. Try a file that exist." << endl;
		}
		if (emp.is_empty(source) && !this->fileExist(source))
		{
			cout << "\aThis file is empty. Try a file with something on it.\n";
		}
	} while (emp.is_empty(source));


	fstream file(source);
	
	while (!file.eof())
	{
		getline(file, content, '~');
	}

	if (file.fail())
	{
		cout << "\aFile with the name of " << source << " does not exist" << endl;
	}
	else
	{
		do
		{
			cout << "Enter the name of the destination file: ";
			cin >> destination;
			destination.append(".txt");
			if (destination == source)
			{
				cout << "\aYou cant clone a file to itself. Try Again. \n\n Destination File: ";
				cin >> destination;
				destination.append(".txt");
			}
		} while (destination == source);
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
	cout << endl;
	cout <<endl;
}

void FileManager::openreadme(){

	ifstream file;

	cout << "Instructions for the program:" << endl;
	cout << endl;
	FileReader fr("readme.txt");
	fr.fileRead();

}

bool FileManager::fileExist(string name) const
{
	ifstream file(name);
	return(file.fail());
}
