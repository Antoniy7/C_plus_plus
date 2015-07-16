#pragma once
#include<cstring>
#include"employee.h"
class Secretary : public Employee
{
private:
	char*languages;
public:
	Secretary(char*egn, char*name, char*address, double salary, char*department, char*languages) :Employee(egn, name, address, salary, department)
	{
		int size = strlen(languages);
		this->languages = new char[size + 1];
		strcpy(this->languages, languages);
	}
	Secretary() : Employee(), languages(NULL)
	{
		
	}
	virtual ~Secretary()
	{
		delete languages;
	}
};