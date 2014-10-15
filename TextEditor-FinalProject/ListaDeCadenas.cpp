#include "ListaDeCadenas.h"


ListaDeCadenas::ListaDeCadenas()
{
	this->cantidad = 0;
}

ListaDeCadenas::ListaDeCadenas(const ListaDeCadenas & unaLista)
{
	(*this) = unaLista;
}

ListaDeCadenas::~ListaDeCadenas()
{
}

ListaDeCadenas & ListaDeCadenas::operator = (const ListaDeCadenas & unaLista)
{
	this->cantidad = unaLista.cantidad;
	for (int i = 0; i < unaLista.cantidad; i++)
		(*this)[i] = unaLista[i];

	return (*this);
}

ListaDeCadenas & ListaDeCadenas:: operator+(const MyString & unaCadena)
{
	this->insertarAlFinal(unaCadena);
	return(*this);
}

ListaDeCadenas & ListaDeCadenas:: operator+(const char * cadena) // PAGINA 6
{
	this->insertarAlFinal(cadena);
	return(*this);
}

ListaDeCadenas & ListaDeCadenas:: operator-(const MyString & unaCadena)
{
	this->remover(this->indiceDeLaUltima(unaCadena));
	return(*this);
}

ListaDeCadenas & ListaDeCadenas:: operator-(const char * cadena) // PAGINA 6
{
	this->remover(this->indiceDeLaUltima(cadena));
	return(*this);

}

ListaDeCadenas & ListaDeCadenas::operator - (int indice)
{
	this->remover(indice);
	return(*this);
}

const MyString & ListaDeCadenas::operator[](int indice) const
{
	return ((this->cadena)[indice]);
}

MyString & ListaDeCadenas::operator[](int indice)
{
	return((this->cadena)[indice]);
}

bool ListaDeCadenas::estaLlena() const
{
	return(this->cantidad == MAX_CAD);

}

bool ListaDeCadenas::estaVacia() const
{
	return(this->cantidad == 0);
}

bool ListaDeCadenas::incluye(const MyString & unaCadena) const
{
	return(this->indiceDe(unaCadena) != -1);
}

bool ListaDeCadenas::incluye(const char * cadena) const
{
	return(this->indiceDe(MyString(cadena)) != -1);
}

int ListaDeCadenas::indiceDe(const MyString & unaCadena) const
{
	int indice = -1;

	for (int i = 0; i < this->cantidad && indice == -1; i++)
	if ((*this)[i] == unaCadena)
		indice = i;

	return(indice);
}

int ListaDeCadenas::indiceDe(const char * cadena) const
{
	return(this->indiceDe(MyString(cadena)));
}

bool ListaDeCadenas::insertar(int indice, const MyString & unaCadena)
{
	bool inserted = false;

	if (!(this->estaLlena()) && indice >= 0 && indice <= this->cantidad)
	{
		for (int i = this->cantidad - 1; i >= indice; i--)
			(*this)[i + 1] = (*this)[i];
		(*this)[indice] = unaCadena;
		++(this->cantidad);
		inserted = true;
	}

	return(inserted);

}

bool ListaDeCadenas::insertar(int indice, const char * cadena)
{
	return(this->insertar(indice, MyString(cadena)));
}

bool ListaDeCadenas::insertarAlComienzo(const MyString & unaCadena)
{
	return(this->insertar(0, unaCadena));
}

bool ListaDeCadenas::insertarAlComienzo(const char * cadena)
{
	return(this->insertar(0, MyString(cadena)));
}

bool ListaDeCadenas::insertarAlFinal(const MyString & unaCadena)
{
	return(this->insertar(this->cantidad, unaCadena));
}

bool ListaDeCadenas::insertarAlFinal(const char * cadena)
{
	return(this->insertar(this->cantidad, MyString(cadena)));
}

void ListaDeCadenas::vaciar()
{
	this->cantidad = 0;
}

int ListaDeCadenas::frecuencia(const char * cadena) const
{
	return(this->frecuencia(MyString(cadena)));
}

int ListaDeCadenas::frecuencia(const MyString & unaCadena) const
{
	int f = 0;

	for (int i = 0; i < this->cantidad; i++)
	if ((*this)[i] == unaCadena)
		++f;

	return(f);
}

bool ListaDeCadenas::remover(int indice, MyString & unaCadena)
{
	bool removed = false;

	if (indice >= 0 && indice < this->cantidad)
	{
		unaCadena = (*this)[indice];
		for (int i = indice; i < (this->cantidad - 1); i++)
			(*this)[i] = (*this)[i + 1];

		--(this->cantidad);
		removed = true;
	}

	return(removed);
}

bool ListaDeCadenas::removerElPrimero(MyString & unaCadena)
{
	return(this->remover(0, unaCadena));
}

bool ListaDeCadenas::removerElUltimo(MyString & unaCadena)
{
	return(this->remover(this->cantidad - 1, unaCadena));
}

ListaDeCadenas & operator +(const char * cadena, ListaDeCadenas & unaLista)
{
	unaLista.insertarAlComienzo(cadena);
	return(unaLista);
}

ostream & operator << (ostream & out, const ListaDeCadenas & unaLista)
{
	if (unaLista.estaVacia())
		out << "La lista esta vacia." << endl;
	else
	for (int i = 0; i < unaLista.cantidad; i++)
		out << (i + 1) << ". " << unaLista[i] << endl;

	return(out);
}

void ListaDeCadenas::ordenarAscendente()
{
	int n = this->cantidad;
	MyString temp;
	bool switched = true;
	
	for (int pass = 0; pass < (n - 1) && switched; pass++)
	for (int j = 0; j < (n - 1 - pass); j++)
	{
		if ((*this)[j] >(*this)[j + 1])
		{
			temp = (*this)[j];
			(*this)[j] = (*this)[j + 1];
			(*this)[j + 1] = temp;
			switched = true;
		}
	}
}

bool ListaDeCadenas::operator == (const ListaDeCadenas & unaLista) const
{
	bool equal = (this-> cantidad == unaLista.cantidad);

	if (equal)
	for (int j = 0; j < this->cantidad && equal; j++)
	if ((*this)[j] != unaLista[j])
		equal = false;

	return(equal);
}

bool ListaDeCadenas::operator != (const ListaDeCadenas & unaLista) const
{
	return(!((*this) == unaLista));
}

void ListaDeCadenas::ordenarDescendente()
{
	int n = this->cantidad;
	MyString temp;

	bool switched = true;

	for (int pass = 0; pass < (n - 1) && switched; pass ++ )
	{
		switched = false;
		for (int j = 0; j < (n - 1 - pass); j++)
		if ((*this)[j] < (*this)[j + 1])
		{
			temp = (*this)[j];
			(*this)[j] = (*this)[j + 1];
			(*this)[j + 1] = temp;
			switched = true;
		}
	}
}

bool ListaDeCadenas::reemplazar(int indice, const char *cadena)
{
	return(this->reemplazar(indice, MyString(cadena)));
}

bool ListaDeCadenas::reemplazar(int indice, const MyString & unaCadena)
{
	bool replaced = false;

	if (indice >= 0 && indice < this->cantidad)
	{
		(*this)[indice] = unaCadena;
		replaced = true;
	}

	return(replaced);

}

bool ListaDeCadenas::remover(int indice)
{
	MyString temporero;

	return(this->remover(indice, temporero));
}

bool ListaDeCadenas::removerElPrimero()
{
	MyString temporero;

	return(this->removerElPrimero(temporero));
}

bool ListaDeCadenas::removerElUltimo()
{
	MyString temporero;
	return(this->removerElUltimo(temporero));
}

ListaDeCadenas & operator - (const char * cadena, ListaDeCadenas & unaLista)
{
	unaLista.remover(unaLista.indiceDe(cadena));

	return(unaLista);
}

ListaDeCadenas & operator - (const MyString & unaCadena, ListaDeCadenas & unaLista)
{
	unaLista.remover(unaLista.indiceDe(unaCadena));
	return(unaLista);
}

int ListaDeCadenas::indiceDeLaUltima(const MyString & unaCadena) const
{
	int indice = -1;
	
	for (int i = this->cantidad - 1; i >= 0 && indice == -1; i--)
	if ((*this)[i] == unaCadena)
		indice = i;

	return(indice);
}

int ListaDeCadenas::indiceDeLaUltima(const char * cadena) const
{
	return(this->indiceDeLaUltima(MyString(cadena)));
}

int ListaDeCadenas::cantidadDeCadenas() const
{
	return(this->cantidad);
}

bool ListaDeCadenas::insertarAlFinal(const ListaDeCadenas & unaLista)
{
	return(this->insertar(this->cantidad, unaLista));
}

bool ListaDeCadenas::insertarAlComienzo(const ListaDeCadenas & unaLista)
{
	return(this->insertar(0, unaLista));
}

bool ListaDeCadenas::insertar(int indice, const ListaDeCadenas & unaLista)
{
	bool inserted = false;
	if (((this->cantidad + unaLista.cantidad) <= MAX_CAD) &&
		(indice >= 0 && indice <= this->cantidad))
	{
		for (int i = 0; i < unaLista.cantidad; i++)
			this->insertar(indice + i, unaLista[i]);
		inserted = true; 
	}

	return(inserted);

}

int ListaDeCadenas::MaxCadenas()
{
	return(MAX_CAD);
}

