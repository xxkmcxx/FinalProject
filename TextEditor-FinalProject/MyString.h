#pragma once
#include<iostream>
using namespace::std;

const int MAX_LEN = 80;

class MyString
{
private:
	char s[MAX_LEN + 1];

public:
	MyString(const char * s = "" );
	MyString(char ch);
	MyString(const MyString & aMyString);

	~MyString();

	MyString & operator =(const char * s);
	MyString & operator =(char ch);
	MyString & operator =(const MyString & aMyString);

	void setS(const char * s);
	const char * getS() const;

	MyString operator +(const char * s) const;
	MyString operator +(char ch) const;
	MyString operator +(const MyString & aMyString) const;
	friend MyString operator +(const char * s, const MyString & aMyString);

	friend MyString operator +(char ch, const MyString & aMyString);

	bool operator ==(const char * s) const;
	bool operator ==(const MyString & aMyString) const;
	friend bool operator==(const char * s, const MyString & aMyString);

	bool operator!=(const char * s) const;
	bool operator !=(const MyString & aMyString)const;
	friend bool operator !=(const char * s, const MyString & aMyString);

	bool operator >(const char * s) const;
	bool operator > (const MyString & aMyString);
	friend bool operator >(const char * s, const MyString & aMyString);

	bool operator < (const char * s) const;
	bool operator < (const MyString & aMyString);
	friend bool operator < (const char * s, const MyString & aMyString);
	
	const char & operator[]	(int index) const;
	char & operator[](int index);

	friend istream & operator >> (istream & in, MyString & aMyString);

	friend ostream & operator << (ostream & out,const  MyString & aMyString);

	MyString trimLeadingSpaces() const;
	MyString trimEndingSpaces() const;
	MyString trimAllSpaces() const;

	MyString toUppercase() const;
	MyString toLowercase() const;

	MyString createSubstring(int from, int to) const;

	int len() const;
	bool isEmpty() const;

	MyString reverse() const;

	int indexOf(char ch) const;
	int indexOfLast(char ch) const;
	bool include(char ch) const;
	int frequency(char ch) const;

	bool representAnUnsignInteger() const;
	bool representAnInteger() const;
	bool representAReal() const;

	static int MaxLen();

	MyString & operator+=(const MyString & aMyString);
	MyString & operator+=(char ch);
	MyString & operator +=(const char * s);

	MyString & operator++();
	MyString operator ++(int);

	MyString & operator --();
	MyString & operator --(int);

};

