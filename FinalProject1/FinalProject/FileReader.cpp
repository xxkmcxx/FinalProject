#include "FileReader.h"
#include <string>


FileReader::FileReader(string name) : f_name(name)
{

}

FileReader::~FileReader()
{

}

void FileReader::fileRead()
{
	fstream file;
	file.open(this->f_name, ios::in);
	

	char ch;
	file.get(ch);
	while (!file.fail())
	{
		cout.put(ch);
		file.get(ch);
	}
	cout << endl;





	//string str;
	/*file >> str;
	while (getline(file, str))
	{
	cout << str << endl;
	}*/
	file.close();

}

int FileReader::ParagraphCount()
{
	ifstream file;
	string s;
	int p_count = 0;

	file.open("pepito.txt");
	if (file.is_open())
	{
		while (getline(file, s, '$'))
		{
			p_count++;
		}
		file.close();
	}
	else
		cout << "Unable to open file.";

	return(p_count);
}
