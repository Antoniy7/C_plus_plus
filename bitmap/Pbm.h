#pragma once
#include"Reader.h"
#include<iostream>
#include"ImageASC.h"
#include <fstream>
#include<cstring>
#include<sstream>
#include<ostream>
using namespace std;

class PBM : public Reader, public ImageASC
{
private:
	char x[10];
	int height;
	int width;
	ifstream file;
public:

	std::ifstream stream;
	PBM(char const* file) : stream(file)
	{
		stream >> x;
		stream >> width;
		stream >> height;
		buf = new int*[height];
		for (int i = 0; i < height; i++)
			buf[i] = new int[width];

		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
				stream>>buf[i][j];
		}	
	}
	void print()
	{
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
				cout<<buf[i][j]<<" ";
			cout << endl;
		}
		
	}





};

