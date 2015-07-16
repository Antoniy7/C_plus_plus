#ifndef Jar_H
#define Jar_H

#include"cookie.h"
#include<fstream>
class Jar
{
private:   
	int capacity;
	char*name;
	int cookie_counter;

	Cookie * list; 
	

public:
	~Jar();
	Jar(size_t capacity);
	void addcookie(const Cookie&c);
	void removeCookie(const Cookie&c);
	bool writeToBinary(const Jar& j, ofstream& out);
	bool readFromBinary(ifstream &in, Jar &j);
	int find_Cookie(const Cookie&c);
	Jar& operator=(const Jar&);

	void setName(const char*name);

};


#endif