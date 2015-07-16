#pragma once
#include"Reader.h"
#include"ImageASC.h"
#include"Transformation.h"
#include<fstream>
#include<iostream>
using namespace std;

class PGM :public Reader, public ImageASC, public Transformation
{

private:
	char x[10];
	int height;
	int width;
	int MaxPix;
	ifstream file;
	ofstream outfile;

public:
	std::ifstream stream;
	PGM(char const* file) : stream(file)
	{
		//stream.open(file);
		stream >> x;
		//cout << x << endl;
		stream >> width;
		stream >> height;
		stream >> MaxPix;

		buf = new int*[height];
		for (int i = 0; i < height; i++)
			buf[i] = new int[width];

		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
				stream >> buf[i][j];
		}
	}
	void print()
	{
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
				cout << buf[i][j] << " ";
			cout << endl;
		}

	}


	bool toMonochrome(const char*output)
	{
		outfile.open(output);
		outfile << "P1" << endl;
		outfile << width << " " << height << endl;
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				if (temporaryTransformation[i][j]>MaxPix)
				{
					outfile << 1;
				}
				else
				{
					outfile << 0;
				}
				if (j == width - 1)
					;

				else{ outfile << " "; }

			}
			outfile << endl;
		}

		outfile.close();

		return true;
	}



};