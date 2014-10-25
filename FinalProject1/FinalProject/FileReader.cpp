#include "FileReader.h"


FileReader::FileReader(string name) : f_name(name)
{
}
FileReader::~FileReader()
{
}
void FileReader:: fileRead()
{
	fstream file;
	file.open(this->f_name,ios::in);
	cout << "This is what the file has currently written" << endl << endl;
	
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
