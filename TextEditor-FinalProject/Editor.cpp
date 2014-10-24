#include "Editor.h"


Editor::Editor(const FileManager & a, const FileManager & b, const FileManager & c){
}

Editor::Editor(const Editor & anEditor){

}

Editor & Editor::operator = (const Editor & anEditor){
	delete[](this->Files);
	if(anEditor.quantityOfFiles){
		this->Files = new FileManager[anEditor.quantityOfFiles];
		for (int i = 0; i < anEditor.quantityOfFiles; i++){
			(*this)[i] = anEditor[i];
		}
	}
	else
		this->Files = NULL;

	this->quantityOfFiles = anEditor.quantityOfFiles;

	return (*this);
}

void Editor::EditWord(){

}

void Editor::EditSentence(){

}
void Editor::EditParagraph(){

}
void Editor::EditWhole(){

}
void Editor::FindEOFSymbol(){

}
void Editor::FindEnterSymbol(){

}
void Editor::FindListSymbol(){

}

Editor::~Editor()
{
}
