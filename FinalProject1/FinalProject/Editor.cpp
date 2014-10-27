#include "Editor.h"
#include<iostream>


Editor::Editor(string name) :f_name(name)
{
	
}

bool Editor::isempty(){

	string filename(this->f_name);
	ifstream in(filename);
	if (!in){
		cout << filename << " failed to open\n";
		return true;
	}
	else {
		return false;
		// Read a character, test for end-of-file
		bool empty = (in.get(), in.eof());
		cout << filename << " is "
			<< (empty ? "" : "not ")
			<< "empty"<<endl;
	}



	/*
	ifstream inFile("a.txt", ios::binary);

	inFile.seekg(0, ios::beg);
	inFile.close();
	if (inFile.peek() == 0){
		cout << "ESTA VACIO." << endl;
		return true;
	}
	if (inFile.get() != 0){
		cout << "NO ESTA VACIO." << endl;
		return false;
	}
		
		// ...do something with empty file...  
	
	
		ifstream file("filename", ios::binary);

		file.seekg(0, ios::end);
		if (file.tellg() == 0)
		{
			cout << "File is empty" << endl;
		}
	}

	
	fstream inFile("file.dat", ios::in | ios::out | ios::binary);
	inFile.seekg(0, ios::end);
	if (inFile.tellg() == 0){

		cout << " VACIO" << endl;
	}
	if (inFile.tellg() != 0){

		cout << "NOESTAVACIO" << endl;
	}
		//File is empty


		int length;
		ifstream f;

		f.open("fileYouWatToTest.txt", ios::app); // open your file
		f.seekg(0, ios::end); // put the "cursor" at the end of the file
		length = f.tellg(); // find the position of the cursor
		f.close(); // close your file

		if (f.peek() == 0)
		return true;
		cout << "El archivo esta vacio." << endl;

		if (f.get() != 0)
		cout << "El archivo NO esta vacio" << endl;
		return false;
		}




		string   s;
		ifstream f(f_name, ios::out);

		// Check for UTF-8 BOM
		if (f.peek() == 0)
		{
		f.get();
		if (f.get() != 0) return false;
		if (f.get() != 0) return false;
		cout << "El archivo esta vacio";
		}

		// Scan every line of the file for non-whitespace characters
		while (getline(f, s))
		{
		if (s.find_first_not_of(
		" \t\n\v\f\r" // whitespace
		"\0\xFE\xFF"  // non-printing (used in various Unicode encodings)
		) != string::npos)
		return false;
		cout << "El archivo no esta vacio.";
		}

		// If we get this far, then the file only contains whitespace
		// (or its size is zero)
		return true;
		cout << "El archivo esta vacio.";

		}

		*/
	
	}

void Editor::editFile()
{
	//this methods needs to validate if the file 
	//has is new or has something written in it
	FileReader reader(this->f_name);
	reader.fileRead();
	file.open(this->f_name,ios::app);

	cout << "You can now start writing into the file." << endl;
	string name;
	getline(cin, name, '-');
	cin.ignore();
	name.append(".");
	file << name;

	file.close();
}
void Editor::readFile(string name)
{
	/*fstream file;
	file.open(name, ios::in);
	string str;
	file >> str;
	while (getline(file, str))
	{
		cout <<str << endl;
	}
*/
}
void Editor::menu()
{
	MyMenu menu;
	int option;
	menu.cambiarTitulo("Welcome to the text editing tool            |");
	menu.agregarOpcion("Start writing into the file       |");
	menu.agregarOpcion("Edit a word on a file             |");
	menu.agregarOpcion("Edit a sentence on a file         |");  //not sure if this option is needed
	menu.agregarOpcion("Edit a paragraph                  |");
	menu.agregarOpcion("Clear file                        |");
	menu.agregarOpcion("Return to previous menu           |");
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
		this->isempty();
		//editWord();
	}
	else if (option == 3)
	{
		//editSentence();
	}
	else if (option == 4)
	{
		//editParagraph();
	}
	else if (option == 5)
	{
		this->clearFile(file);		
		this->menu();
	}
	else if (option == 6)
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
void Editor::clearFile(fstream &file)
{
	/*file.close();
	file.open("Kevin.txt", ios::out | ios::trunc);
	file.close();
	file.open("Kevin.txt", ios::in | ios::app);
	cout << "File cleared" << endl;*/
}
Editor::~Editor()
{
	
}

