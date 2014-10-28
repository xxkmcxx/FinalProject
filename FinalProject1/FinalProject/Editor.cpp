#include "Editor.h"
#include<iostream>
#include "FileManager.h"


Editor::Editor(string name) :f_name(name), reader(name)
{
	
}

bool Editor::isempty(){

	string filename(this->f_name);
	ifstream in(filename);
	if (!in){
		cout << filename << " failed to open\n";
		return false;
	}
	else {
		return true;
		// Read a character, test for end-of-file
		bool empty = (in.get(), in.eof());
		cout << filename << " is "
			<< (empty ? "" : "not ")
			<< "empty"<<endl;
	}
	
		}

void Editor::editFile()
{
	FileReader emp(f_name);
	//this methods needs to validate if the file 
	//has is new or has something written in it
	if (emp.is_empty(f_name))
	{
		cout << "File is empty." << endl;
	}
	else
	{
		cout << "This is what the file has currently written" << endl << endl;
	}

	this->reader.fileRead();
	file.open(this->f_name,ios::app);

	cout << "You can now start writing into the file." << endl;
	string n_text,text;
	getline(cin, n_text, '~');
	cin.ignore();
	text  = n_text.substr(1, n_text.length());
	file << text;

	file.close();
}

void Editor::clearFile()
{
	string yn;
	cout << "Are you sure you want to delete the file. After is done you cant undo. Y/N: ";
	cin >> yn;
	while(yn != "y" || yn != "Y" || yn!="n"|| yn!= "N")
	{
		cout << "Didn't get that. Try again. \n Yes or No? ";
		cin >> yn;
	}
	if (yn == "Y" || yn == "y")
	{
		FileManager Mana;
		Mana.loading();
		this->file.open(this->f_name, ios::out | ios::trunc);
		file.close();
		cout << "File cleared" << endl;
	}
	else 
		cout << "File wasn't deleted. Returning to main menu." << endl;
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

void Editor::editWord()
{
	string word, content, word2;
	int c = 1, i = 0, pos = 0;
	cout << "Type in the word you want to edit. Please type as it is in the file : ";
	cin >> word;
	cout << "Enter the replacement word :";
	cin >> word2;
	ifstream emp(f_name);
	while (!emp.eof())
	{
		getline(emp, content, '~');
		emp.close();
	}
	fstream emp2(f_name);
	size_t Found = content.find(word);
	cout << "We found " << word << " on: " << endl;
	if (Found != string::npos)
	{
		cout << '\t' << i + 1 << ')' << Found << endl;
		i++;
	}
	for (int g = Found; g == Found;)
	{
		g = Found;
		Found = content.find(word, Found + 1);
		if (Found > g && Found < 300)
		{
			cout << '\t' << i + 1 << ')' << Found << endl;
			i++;
			g = Found;
		}
		if (g == Found - 1)
		{
			g = 0;
		}
	}
	cout << "Enter the position of the word: ";
	cin >> pos;
	int a = word.length();
	if (word.length() > word2.length())
	{
		a = word.length() - word2.length();
	}
	if (word.length() < word2.length())
	{
		a = word2.length() - word.length();
	}

	if (word.length() < word2.length())
		content.replace(pos, word.length() + a - 1, word2);
	if (word.length() > word2.length())
	{
		for (int q = 0; q < (word.length() - word2.length());q++)
			content.append("\b\b");
		content.replace(pos, word.length() - a + (word.length() - word2.length()), word2);
	}


	emp2 << content;
	emp2.close();
}

void Editor::deleteWord()
{
	string word, content, word2;
	int c = 1, i = 0, pos = 0;
	cout << "Type in the word you want to delete. Please type as it is in the file : ";
	cin >> word;
	ifstream emp(f_name);
	while (!emp.eof())
	{
		getline(emp, content, '~');
		emp.close();
	}
	fstream emp2(f_name);
	size_t Found = content.find(word);
	cout << "We found " << word << " on: " << endl;
	if (Found != string::npos)
	{
		cout << '\t' << i + 1 << ')' << Found << endl;
		i++;
	}
	for (int g = Found; g == Found;)
	{
		g = Found;
		Found = content.find(word, Found + 1);
		if (Found > g && Found < 300)
		{
			cout << '\t' << i + 1 << ')' << Found << endl;
			i++;
			g = Found;
		}
		if (g == Found - 1)
		{
			g = 0;
		}
	}
	cout << "Enter the position of the word: ";
	cin >> pos;
	for (int q = 0; q < word.length(); q++)
	{
		content.append("\b");
	}
	content.erase(pos, word.length());

	emp2 << content;
	emp2.close();
}

Editor::~Editor()
{
	
}

void Editor::menu()
{
	MyMenu menu;
	string option;
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

	if (option == "1")
	{
		this->editFile();
		this->menu();
	}
	else if (option == "2")
	{
		this->reader.fileRead();
		this->menu();
	}
	else if (option == "3")
	{
		this->editWord();
		this->menu();
	}
	else if (option == "4")
	{
		this->deleteWord();
		this->menu();
	}
	else if (option == "5")
	{
		this->editLine();
		this->menu();
	}
	else if (option == "6")
	{
		this->deleteLine();
		this->menu();
	}
	else if (option == "7")
	{
		this->editParagraph();
		this->menu();
	}
	else if (option == "8")
	{
		this->deleteParagraph();
		this->menu();
	}
	else if (option == "9")
	{
		this->clearFile();
		this->menu();
	}
	else if (option == "10")
	{
		cout << "Saving document..." << endl
			<< "Now going back to previous menu." << endl;
		return;
	}
	else
	{
		cout << "\aInvalid input, please try again" << endl;
		this->menu();
	}
}