#include "FileManager.h"


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
			this->openFile();
			this->menu();
		}
		else if (option == 2)
		{
			//openExistingFile();
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