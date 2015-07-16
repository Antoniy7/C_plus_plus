#include"cookie.h"
#include<cstring>
#include<iostream>
#include<fstream>
using namespace std;

int Fixed_string_number = 3;
int current_position = 0;

void Cookie::fill_Cookie(int string_counter)
{	
	char *y = new char[400];
	cin.get(y, 400);
	this->cookie = new char*[Fixed_string_number];
	char *pch;
	pch = strtok(y, " ,.-");
	
	while (pch != NULL)
	{
		size_t l = strlen(pch) + 1;
		this->cookie[current_position] = new char[l];
		strcpy_s(this->cookie[current_position], l, pch);
		
		current_position++;
		
		pch = strtok(NULL, " ,.-");
	}
	delete[]y;
}

Cookie::~Cookie()
{
	for (int i = 0; i < current_position; i++)
		delete cookie[i];
	delete cookie;
}

bool Cookie::operator==(const Cookie& right)const
{
	for (int i = 0; i < current_position; i++)
	{
		if (strcmp(cookie[i], right.cookie[i]) != 0)
			return false;
	}
	return true;
}


bool Cookie::writeToBinary(const Cookie& c, ofstream& out)
{
	if (!out) return false;

	out.write((const char*)&Fixed_string_number, sizeof(int)); 
	for (int i = 0; i < Fixed_string_number; i++)
	{	
		size_t l = strlen(arr[i]);
		out.write((const char*)&l, sizeof(l));
		out.write((const char*)&cookie[i], sizeof(Cookie));
	}
	return out.good();
}

bool Cookie::readBinary(ifstream &in,const Cookie &c)
{
	if (!in) return false;

	int cookie_counter;
	in.read((char*)&cookie_counter, sizeof(int));

	Cookie * temp = new Cookie[cookie_counter];

	for (int i = 0; i < cookie_counter; i++)
	{
		in.read((char*)&temp[i], sizeof(Cookie));
	}

	//delete[] temp;

	return in.good();    // vrushtame sustoqnieto na potoka
}