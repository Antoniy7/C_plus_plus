#pragma once
#include<cstring>
#include"employee.h"
#include<iostream>
using namespace std; 
#include"temp.h"

int Employee::counter = 0;
int Employee::size = 10;

//Employee*arr=new Employee[10];


Employee::Employee(char*egn, char*name, char*address, double salary, char*department)
{
	counter++;

	set(egn, this->egn);
	set(name, this->name);
	set(address, this->address);
	set(department, this->department);
	this->salary = salary;
	
	//void Temp::add(*this);
	//friend void temp::print(ONE& x);
	//add(this);
		
//	arr[counter - 1] = *this;
}

void Employee::set(char*thing,char* &place)
{
        delete [] place;
	int size = strlen(thing);
	place = new char[size + 1];
	strcpy(place, thing);

}
Employee::Employee(char*egn, char*name): egn(NULL), name(NULL)
{
	set(egn, this->egn);
	set(name, this->name);
}
void Employee::print()
{
	int n = strlen(this->address);
	for (int i = 0; i < n; i++)
		cout << *(address + i);
}
Employee::~Employee()
{
	del();


}
void Employee::del()
{
	delete this->name;
	delete this->address;
	delete this->egn;
	delete this->department;
}

Employee::Employee(const Employee & other)
{
	set(other.egn, this->egn);
	set(other.name, this->name);
	set(other.address, this->address);
	set(other.department, this->department);
	this->salary = other.salary;
}

Employee& Employee::operator=(const Employee &right)
{
	
	if (this == &right)
		return *this;

	set(right.egn, this->egn);
	set(right.name, this->name);
	set(right.address, this->address);
	set(right.department, this->department);
	this->salary = salary;

	return *this; 
}

void Employee::set_address(char*address)
{
	set(address, this->address);
}
void Employee::set_name(char*name)
{
	set(name, this->name);
}
void Employee::set_department(char*department)
{
	set(department, this->department);
}
void Employee::set_egn(char*egn)
{
	set(egn, this->egn);
}
void Employee::set_salary(double salary)
{
	this->salary = salary;
}

char* Employee::get_address()
{
	return this->address;
}

char* Employee::get_department()
{
	return this->department;
}
double Employee::get_salary()
{
	return this->salary;
}
char* Employee::get_name()
{
	return this->name;
}
char* Employee::get_egn()
{
	return this->egn;
}

//void Employee::resize_static()
//{
//	if (counter > size)
//	{
//		Employee*temp = new Employee[size*2];
//		for (int i = 0; i < counter - 1; i++)
//		{
//			temp[i].set_address(arr[i].address);
//			temp[i].set_department(arr[i].department);
//			temp[i].set_egn(arr[i].egn);
//			temp[i].set_salary(arr[i].salary);
//			temp[i].set_name(arr[i].name);
//			
//		}
//		delete[] arr;
//		arr = temp;
//	}
//}