#include<cstring>
#include"Doctor.h"
#include"patient.h"
using namespace std;

Doctor::Doctor(const char*name, size_t cap) :name(NULL), count(0), capacity(cap), list(new Patient[capacity])  
{
	this->setName(name);
	//this->count=0
	this->list = new Patient[capacity];
}

//copy constr
Doctor::Doctor(const Doctor& other) :name(NULL), count(other.count), capacity(other.capacity)
{
	this->setName(other.name); 
	this->list = new Patient[capacity];
	for (size_t i = 0; i < count; i++)
	{
		this->list[i] = other.list[i]; 
	}
}

Doctor& Doctor::operator=(const Doctor& right)
{
	if (this == &right) return *this;
	this->setName(right.name);
	delete[] this->list;
	this->count = right.count;
	this -> capacity = right.capacity;
	this->list = new Patient[capacity];
	for (size_t i = 0; i < count; i++)
	{
		this->list[i] = right.list[i];
	}
	return  *this;

}
void Doctor::addPatient(const Patient&p)
{
	if (count < capacity)
	{
		list[count] = p;
		count++;
	}
	else
	{
		Patient * temp = new Patient[capacity * 2];
		for (size_t i = 0; i < count; i++)
		{
			temp[i] = list[i];
		}
		temp[count] = p;
		count++;
		capacity *= 2;
		delete[] list;
		list = temp; 
	}
}
void resize(int)
{

}

void Doctor::removePatient(const Patient& p)
{
	int pos = findPatient(p);
	if (pos == -1)
		return;

	list[pos] = list[count - 1];
	count--;
	if (4 * count < capacity)
		resize(capacity / 2);
}

int Doctor::findPatient(const Patient& p)
{
	for (size_t i = 0; i < count; i++)
	{
		if (list[i] == p)
			return i;

	}
	return -1;
}

void Doctor:: searchPatients(bool(*pred)(const Patient&))
{
	for (size_t i = 0; i < count; i++)
	{
		if (pred(list[i]))
			list[i].print();
	}
}

bool vac(const Patient&p)
{
	//const char* a = p.getName();
	const char* e = p.getEGN();
	if (e[0] == '8' && e[1] == '9')
		return true;
	else return false;
}     

Doctor& operator +=(const Patient& right)
{
	this->addPatient((right));
	return *this;
}
Doctor operator+(const Patient& right) const
{
	Doctor result = *this;
	result += right;

	return result;


}