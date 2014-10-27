#include "Editor.h"


Editor::Editor(string name) :f_name(name), reader(name)
{
	
}
void Editor:: editFile()
{
	//this methods needs to validate if the file 
	//has is new or has something written in it
	this->reader.fileRead();
	file.open(this->f_name,ios::app);

	cout << "You can now start writing into the file." << endl;
	string n_text,text;
	getline(cin, n_text, '-');
	cin.ignore();
	text  = n_text.substr(1, n_text.length());
	file << text;

	file.close();
}

void Editor::clearFile()
{
	
	this->file.open(this->f_name, ios::out | ios::trunc);
	file.close();
	cout << "File cleared" << endl;
}
void Editor::editLine()
{
	
	int l_number;
	cout << "Enter the number of the line you want to replace" << endl;
	cin >> l_number;
	this->reader.lineReplace(l_number);
}
void Editor::deleteLine()
{
	int l_number;
	cout << "Enter the number of the line you want to delete" << endl;
	cin >> l_number;
	this->reader.deleteLine(l_number);
}
void Editor::editParagraph()
{
	int p_number;
	cout << "Enter the number of the paragraph" << endl;
	cin >> p_number;
	this->reader.paragraphReplace(p_number);
}
void Editor::deleteParagraph()
{
	int p_number;
	cout << "Enter the number of the paragraph" << endl;
	cin >> p_number;
	this->reader.deleteParagraph(p_number);
}
Editor::~Editor()
{
	
}
void Editor::menu()
{
	MyMenu menu;
	int option;
	menu.cambiarTitulo("Welcome to the text editing tool            |");
	menu.agregarOpcion("Start writing into the file.      |");
	menu.agregarOpcion("View file content.                |");
	menu.agregarOpcion("Edit a word.                      |");
	menu.agregarOpcion("Delete a word.                    |");
	menu.agregarOpcion("Edit a line.                      |");
	menu.agregarOpcion("Delete a line.                    |");
	menu.agregarOpcion("Edit a paragraph.                 |");
	menu.agregarOpcion("Delete a paragraph.               |");
	menu.agregarOpcion("Clear file.                       |");
	menu.agregarOpcion("Return to previous menu.         |");
	menu.cambiarPregunta("Please choose one of the option shown above.|");

	cout << "____________________________________________" << endl;
	cout << menu << endl;
	cout << "____________________________________________" << endl;

	cin >> option;

	if (option == 1)
	{
		this->editFile();
		this->menu();
	}
	else if (option == 2)
	{
		this->reader.fileRead();
		this->menu();
	}
	else if (option == 3)
	{
		//editWord();
	}
	else if (option == 4)
	{
		//deleteWord();
	}
	else if (option == 5)
	{
		this->editLine();
		this->menu();
	}
	else if (option == 6)
	{
		this->deleteLine();
		this->menu();
	}
	else if (option == 7)
	{
		this->editParagraph();
		this->menu();
	}
	else if (option == 8)
	{
		this->deleteParagraph();
		this->menu();
	}
	else if (option == 9)
	{
		this->clearFile();
		this->menu();

	}
	else if (option == 10)
	{
		cout << "Saving document..." << endl
			<< "Now going back to previous menu." << endl;
		return;
	}
	else
	{
		cout << "Invalid input, please try again" << endl;
		this->menu();
	}
}
