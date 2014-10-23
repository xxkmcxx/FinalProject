#pragma once
#include "FileManager.h"

class Editor
{
private:
	FileManager * Files;
	int quantityOfFiles;
public:
	Editor(const FileManager & a, const FileManager & b, const FileManager & c);
	Editor(const Editor & aEditor);
	~Editor();
	Editor & operator = (const Editor & aEditor);
	void EditWord();
	void EditSentence();
	void EditParagraph();
	void EditWhole();
	void FindEOFSymbol();
	void FindEnterSymbol();
	void FindListSymbol();

};

