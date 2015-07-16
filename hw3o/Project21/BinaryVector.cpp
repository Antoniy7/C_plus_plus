#include"BinaryVector.h"
#include<iostream>
using namespace std;

const int size=32; // size of elements

BinaryVector::BinaryVector()
{
	for (int i = 0; i < size; i++)
		this->binary_vector[i] = 0;
}

const int BinaryVector::operator[](int index)const
{
	if (index>=size || index < 0)
		return -1;
	else 
		return binary_vector[index];
}
bool BinaryVector::set(int index)
{
	if (index >= size || index < 0)
		return false;
	else
		binary_vector[index] = 1;
	
	return true;
}
bool BinaryVector::clear(int index)
{
	if (index >= size || index < 0)
		return false;

	else binary_vector[index] = 0;
	
	return true;
}
 void BinaryVector::print() 
{
	for (int i = 0; i < size; i++)
		cout << binary_vector[i] << " ";
}
