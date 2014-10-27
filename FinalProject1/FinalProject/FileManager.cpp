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
			this->createFile();
			this->menu();
		}
		else if (option == 2)
		{
			this->openFile();
			this->menu();
		}
		else if (option == 3)
		{
			cout << "Thank you,Bye!" << endl;
			return;
		}
		else
		{
			cout << "Invalid input, please try again" << endl;
			this->menu();
		}
}

int FileManager::openFile()
{
	string name;
	cout << "Enter the name of the file to open" << endl;
	cin >> name;
	name.append(".txt");

	fstream file;
		if(file.fail())
		{
			cout << "File with the name of " << name << "does not exist" << endl;
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
	cout << "File creation was succeful!" << endl;
	fstream file;
	if (file.fail())
	{
		cout << "Whoops! The file is missing." << endl;
	}
	else
	{
		file.close();
		Editor edit(name);
		edit.menu();
	}
	file.close();
}

void FileManager::loading()
{
	double progress = 0.0;
	while (progress <= 1.0) 
	{
		int barWidth = 55;

		std::cout << "[";
		int pos = barWidth * progress;
		for (int i = 0; i <= barWidth; ++i) {
			if (i < pos) std::cout << "=";
			else if (i == pos) std::cout << ">";
			else std::cout << " ";
			Sleep(1);
		}
		std::cout << "] " << int(progress * 100.1) << " %\r";
		std::cout.flush();

		progress += 0.10;
	}
	std::cout << std::endl;
}

