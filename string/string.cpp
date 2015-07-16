#include"String.h"
#include<cassert>
#include<iostream>
#include<cstring>
using namespace std;

void::String::setData(const char*d)
{
	length = strlen(d);
	data = new char[length + 1];
	strcpy_s(data, length + 1, d);
}

String::String(const String& other) //copy constr
{
	setData(other.data);
}

String::String(const char*d)
{
	setData(d);
}

String::~String()
{
	delete[]data;
}

String& String::operator=(const String&other)
{
	if (this == &other) return *this;

	delete[]data;
	setData(other.data);
	return *this;
}
//vrushtame promeneniq teksusht obekt
String& String::operator+=(const String&other)  //nashiq str = "abc"   durgiq "de"   kraq  abcde :) 
{
	int promenlva = length + other.length + 1;
	char * buffer = new char[this->length + other.length + 1];
	strcpy_s(buffer, length + other.length + 1, this->data);
	//strcpy_s(buffer+length,); // ne po4vame ot na4aloto mi po napred
	strcat_s(buffer, length + other.length + 1, other.data);

	delete[] this->data;
	this->data = buffer;
	this->length += other.length;

	return *this; // vrushtame promeneniq tekusht obekt :)
}

String String::operator+(const String& other) const
{
	String result = *this; 
	result += other;//nasheto += ot odeve
	
	return result;
}

bool String::operator!()const
{
	
	return length == 0;
	
}

char& String::operator[](size_t index)
{
	assert(index<length);
	return data[index];   
	//side note//drugiq deto e s const pak e sushtiq :) 
}

bool String::operator==(const String& other)const
{
	return strcmp(data, other.data) == 0;
}

bool String::operator!=(const String& other) const
{
	return !(*this == other); 
	//samo si q definirai v header :) 
}

bool String::operator>(const String& other)const
{
	return strcmp(data, other.data) > 0;
}

bool String::operator>=(const String& other)const
{
	return (* this> other) || (*this==other); 
}

bool String::operator<(const String& other)const
{
	return !(*this >= other);
}
bool String::operator<=(const String& other)const
{
	return !(*this > other);
}

String String::operator()(size_t position, size_t count) const 
{
	if (position >= this->length)  return "";     
	if (position + count > length)         
		count = length - position;

	char* buffer = new char[count + 1]; 
	strncpy_s(buffer, count + 1, this->data + position);  

	String result(buffer);

	delete[] buffer;

	return result;
}

String ::operator const char *()const
{
	

	return data; 
}
