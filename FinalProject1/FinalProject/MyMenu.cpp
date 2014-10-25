#include "MyMenu.h"


MyMenu::MyMenu(const MyString & titulo, const MyString & pregunta)
{
	(*this) + titulo;
	(*this) + pregunta;

}

MyMenu::MyMenu(const char * titulo, const char * pregunta)
{
	(*this) + titulo;
	(*this) + pregunta;
}

MyMenu::MyMenu(const MyMenu & unMenu):lista(unMenu.lista)
{

}

MyMenu::~MyMenu()
{
}

MyMenu & MyMenu::operator = (const MyMenu & unMenu)
{
	this->lista = unMenu.lista;
	return(*this);
}

void MyMenu::cambiarTitulo(const MyString & titulo)
{
	(*this)[0] = titulo;
}

void MyMenu::cambiarTitulo(const char * titulo)
{
	(*this)[0] = titulo;
}

void MyMenu::cambiarPregunta(const MyString & pregunta)
{
	(*this)[1] = pregunta;

}

void MyMenu::cambiarPregunta(const char * pregunta)
{
	(*this)[1] = pregunta;
}

const MyString & MyMenu::obtenerTitulo() const
{
	return((*this)[0]);
}

const MyString & MyMenu::obtenerPregunta() const
{
	return((*this)[1]);
}

int MyMenu::cantidadDeOpciones() const
{
	return((this->lista).cantidadDeCadenas() - 2);
}

MyMenu & MyMenu::operator +(const MyString & opcion)
{
	(this->lista) + opcion;
	return(*this);
}

MyMenu & MyMenu::operator +(const char * opcion)
{
	(this->lista) + opcion; 
	return(*this);
}

const MyString & MyMenu::operator[] (int indice) const
{
	return((this->lista)[indice]);
}

MyString & MyMenu::operator [](int indice)
{

	return((this->lista)[indice]);
}

ostream & operator << (ostream & out, const MyMenu & unMenu)
{
	out << unMenu.obtenerTitulo() << endl;
	for (int i = 0; i < unMenu.cantidadDeOpciones(); i++)
		out << '\t' << (i + 1) << "." << unMenu[i + 2] << endl;
	out << unMenu.obtenerPregunta();

	return(out);
}

void MyMenu::cambiarOpcion(int indice, const MyString & opcion)
{
	int cantidad = this->cantidadDeOpciones();

	if (indice >= 0 && indice < cantidad)
		(*this)[indice + 2] = opcion;

}

void MyMenu::cambiarOpcion(int indice, const char * opcion)
{
	this->cambiarOpcion(indice, MyString(opcion));
}

const MyString & MyMenu::obtenerOpcion(int indice) const
{
	return((*this)[indice + 2]);
}

bool MyMenu::agregarOpcion(const MyString & opcion)
{
	return((this->lista).insertarAlFinal(opcion));
}

bool MyMenu::agregarOpcion(const char * opcion)
{
	return((this->lista).insertarAlFinal(opcion));
}
