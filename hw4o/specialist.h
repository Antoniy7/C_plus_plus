#pragma once 
#include<cstring>
#include"employee.h"
//#include"temp.h"

class Specialist :public Employee
{
	//friend class Temp;
protected:
	char*description;


public:
	Specialist(char*egn, char*name, char*address, double salary, char*department, char*description) :Employee(egn, name, address, salary, department)
	{
		Employee::counter--;
		
		int size = strlen(description);
		this->description = new char[size + 1];
		strcpy(this->description, description);
	}
	Specialist() :Employee(), description(NULL)
	{
	}

	virtual ~Specialist()
	{
		delete description;
	}

	Specialist& operator=(const Specialist &right)
	{

		if (this == &right)
			return *this;

               Employee::opeprator=(right);  // vmesto dolnite  5-6 reda

		set(right.description, this->description);
		set(right.egn, this->egn);
		set(right.name, this->name);
		set(right.address, this->address);
		set(right.department, this->department);
		this->salary = salary;

		return *this;
	}


	Specialist::Specialist(const Specialist & other):Employees(right)
	{
                    // vmesto dolnite  5-6 reda
		set(other.egn, this->egn);
		set(other.name, this->name);
		set(other.address, this->address);
		set(other.department, this->department);
		this->salary = other.salary;
		set(other.description, this->description);
	}


};