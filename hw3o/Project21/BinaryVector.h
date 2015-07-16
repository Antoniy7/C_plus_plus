#pragma once 

class BinaryVector
{
private :
   // int size = 32;
	bool binary_vector[32];
	

public:
	void print();
	BinaryVector();
	//BinaryVector(const BinaryVector&other);
	~BinaryVector(){};
	
	const int operator[](int index)const;
	bool set(int);
	bool clear(int);


};