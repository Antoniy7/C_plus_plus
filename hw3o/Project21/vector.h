#pragma once

class Vector
{
private:
	double *elements;
	int size;
	//int capacity;
	void resize(int size);
	void copy(const Vector& other);
	
public:
	Vector();
	Vector(int size);
	~Vector();
	void print();
	void fill();
	const double operator[](size_t position)const;
	Vector& operator+=(const Vector&other);
	Vector& operator-=(const Vector&other);
	Vector& operator=(const Vector&right);
	Vector operator+(const Vector&other) const;
	Vector operator-(const Vector&other) const;
	Vector(const Vector&other);
	Vector operator*(double scalar);
	Vector& operator*=(double scalar);
	Vector operator/(double scalar);
	Vector& operator/=(double scalar);
	double operator%(const Vector&other);

};