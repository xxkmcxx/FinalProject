#include <iostream>
#include "ListaDeCadenas.h"
#include "..\Type\MyString.h"

using namespace std;

#pragma once
class MyMenu
{

private: 
	ListaDeCadenas lista;

	const MyString & operator [] (int indice) const;
	MyString & operator [] (int indice);

public:
	MyMenu(const MyString & titulo = "Titulo", const MyString & pregunta = "Pregunta");
	MyMenu(const char * titulo, const char * pregunta);
	MyMenu(const MyMenu & unMenu);

	~MyMenu();

	MyMenu & operator = (const MyMenu & unMenu);

	void cambiarTitulo(const MyString & titulo);
	void cambiarTitulo(const char * titulo);
	void cambiarPregunta(const MyString & pregunta);
	void cambiarPregunta(const char * pregunta);
	void cambiarOpcion(int indice, const MyString & opcion);
	void cambiarOpcion(int indice, const char * opcion);

	const MyString & obtenerTitulo() const;
	const MyString & obtenerPregunta() const;
	const MyString & obtenerOpcion(int indice) const;

	int cantidadDeOpciones() const;

	bool agregarOpcion(const MyString & opcion);
	bool agregarOpcion(const char * opcion);

	MyMenu & operator + (const MyString & opcion);
	MyMenu & operator + (const char * opcion);

	friend ostream & operator << (ostream & out, const MyMenu & unMenu);

};

