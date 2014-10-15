#include <iostream>
#include "..\Type\MyString.h"

const int MAX_CAD = 80;

#pragma once
class ListaDeCadenas
{

private:
	MyString cadena[MAX_CAD];
	int cantidad;

public:
	ListaDeCadenas();
	ListaDeCadenas(const ListaDeCadenas & unaLista);

	~ListaDeCadenas();

	ListaDeCadenas & operator = (const ListaDeCadenas & unaLista);

	int cantidadDeCadenas() const;

	bool operator == (const ListaDeCadenas & unaLista) const;
	bool operator != (const ListaDeCadenas & unaLista) const;


	bool insertar(int indice, const MyString & unaCadena);
	bool insertar(int indice, const char * cadena);
	bool insertar(int indice, const ListaDeCadenas & unaLista);

	bool insertarAlComienzo(const MyString & unaCadena);
	bool insertarAlComienzo(const char * cadena);
	bool insertarAlComienzo(const ListaDeCadenas & unaLista);

	bool insertarAlFinal(const MyString & unaCadena);
	bool insertarAlFinal(const char * cadena);
	bool insertarAlFinal(const ListaDeCadenas & unaLista);

	ListaDeCadenas & operator + (const MyString & unaCadena);
	ListaDeCadenas & operator + (const char * cadena);
	ListaDeCadenas & operator + (const ListaDeCadenas & unaLista);
	friend ListaDeCadenas & operator + (const char * cadena, ListaDeCadenas & unaLista);

	friend ListaDeCadenas & operator + (const MyString & unaCadena, ListaDeCadenas & unaLista);


	bool estaLlena() const;
	bool estaVacia() const;

	bool incluye(const MyString & unaCadena) const;
	bool incluye(const char * cadena) const;

	int indiceDe(const MyString & unaCadena) const;
	int indiceDe(const char * cadena) const;
	int indiceDeLaUltima(const MyString & unaCadena) const;
	int indiceDeLaUltima(const char * cadena) const;

	bool remover(int indice);
	bool removerElPrimero();
	bool removerElUltimo();
	bool remover(int indice, MyString & unaCadena);
	bool removerElPrimero(MyString & unaCadena);
	bool removerElUltimo(MyString & unaCadena);

	ListaDeCadenas & operator - (const MyString & unaCadena);
	ListaDeCadenas & operator - (const char * cadena);
	ListaDeCadenas & operator - (const ListaDeCadenas & unaLista);
	ListaDeCadenas & operator -(int indice);
	friend ListaDeCadenas & operator - (const char * cadena, ListaDeCadenas & unaLista);
	friend ListaDeCadenas & operator - (const MyString & unaCadena, ListaDeCadenas & unaLista);

	void vaciar();

	void ordenarAscendente();
	void ordenarDescendente();

	bool reemplazar(int indice, const MyString & unaCadena);
	bool reemplazar(int indice, const char * cadena);

	const MyString & operator [] (int indice) const;
	MyString & operator [] (int indice);

	int frecuencia(const MyString & unaCadena) const;
	int frecuencia(const char * cadena) const;

	static int MaxCadenas();

	friend ostream & operator << (ostream & out, const ListaDeCadenas & unaLista);

};

