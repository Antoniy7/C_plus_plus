#include<cstring>
#include "cookie.h"
#include"jar.h"
using namespace std;

Jar::Jar( size_t cap) :cookie_counter(0),capacity(cap)  
{ 	
	this->list = new Cookie[capacity];
}

bool Jar::writeToBinary(const Jar& j, ofstream& out)
{
	if (!out) return false;

	out.write((const char*)&cookie_counter, sizeof(int));
	for (int i = 0; i < cookie_counter; i++)
		out.write((const char*)&j.list[i], sizeof(Cookie));   
	
	return out.good();
}

bool Jar::readFromBinary(ifstream &in, Jar &j)
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

	return in.good();    
}
void Jar::addcookie(const Cookie&c)
{
	cookie_counter++;

		Cookie * temp = new Cookie[cookie_counter];
		for (size_t i = 0; i < cookie_counter; i++)
		{
			temp[i] = list[i];
		}
		
		delete[] list;
		list = temp; 
}

int Jar::find_Cookie(const Cookie& c)
{
	for (size_t i = 0; i < cookie_counter; i++)
	{
		if (list[i] == c)
			return i;

	}
	return -1;
}

void Jar::removeCookie(const Cookie&c)
{
	Cookie * temp = new Cookie[cookie_counter-1];
	list = temp;
	cookie_counter--;
}



