#include"vector.h"
#include<iostream>
using namespace std;

Vector::Vector()
{
	elements = NULL;
	this->size = 0;
}
Vector::Vector(int size)
{
	elements = new double [size];
	this->size = size;
	
}
void Vector::resize(int size)
{
	double* temp = new double[size];
	for (int i = 0; i < this->size; i++)
		temp[i] = elements[i];
	for (int i = this->size; i < size; i++)
		temp[i] = 0;
	delete[] elements;
	elements = temp;
	this->size = size;
}

void Vector::print()
{
	for (int i = 0; i < size; i++)
		cout << elements[i] << "  ";

}

void Vector::fill()
{
	for (int i = 0; i < size; i++)
	{
		elements[i] = (i * 2) + 1.22;
	}

}

Vector::~Vector()
{
	delete[] elements;
	elements = NULL;
}

const double Vector::operator[](size_t position)const
{
	if (position < 0)
		return 1;

	else return elements[position];
}


Vector& Vector::operator+=(const Vector&other)  
{
	if (this->size < other.size)
		resize(other.size);
	
	for (int i = 0; i < other.size; i++)
		elements[i] += other.elements[i];
	
	return *this; 
}


void Vector::copy(const Vector& other)
{
	size = other.size;

	elements = new double[size];

	for (int i = 0; i < size; ++i)
	{
		elements[i] = other.elements[i];
	}
}
Vector& Vector::operator=(const Vector& vector)
{
	if (this == &vector) return *this;

	delete[] elements;
	elements = new double[vector.size];
	for (int i = 0; i < vector.size; i++)
		elements[i] = vector.elements[i];

	return *this;
}
Vector::Vector(const Vector&other) //copy constr
{
	copy(other);
}


Vector Vector::operator+(const Vector&other)const
{
	Vector result = *this; //copy constr vikame tuk 
	result += other;  //predefiniranoto +=
	return result;
}
Vector& Vector::operator-=(const Vector&other)
{
	if (this->size < other.size)
		resize(other.size);

	for (int i = 0; i < other.size; i++)
		elements[i] -= other.elements[i];

	return *this;
}
Vector Vector::operator-(const Vector&other)const
{
	Vector result = *this; //copy constr vikame tuk 
	result -= other;
	return result;
}
Vector& Vector::operator*=(double scalar)
{
	for (int i = 0; i < size; i++)
		elements[i] *= scalar;

	return *this;
}
Vector Vector::operator*(double scalar) 
{
	Vector result = *this;
	result *= scalar;

	return result;
}
Vector& Vector::operator/=(double scalar)
{
	for (int i = 0; i < size; ++i)
		elements[i] /= scalar;

	return *this;
}

double Vector::operator%(const Vector& other)
{
	double scalar=0;
	for (int i = 0; i < size; i++)
		scalar = (elements[i] * other.elements[i]);
	return scalar;
}