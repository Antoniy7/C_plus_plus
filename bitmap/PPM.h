#pragma once
#include"Transformation.h"
#include"Reader.h"
#include"ImageASC.h"
#include<fstream>
#include<cstring>
#include<iostream>

using namespace std;

class PPM :public Reader, public ImageASC, public Transformation
{

private:
	char x[10];
	int height;
	int width;
	const int NumberofPixels = 3;
	int MaxPix;
	ifstream file;
	ofstream outfile;
	const double redCoefficientToGrayScale = 0.21;
	const double greenCoefficientToGrayScale = 0.72;
	const double blueCoefficientToGrayScale =  0.07;
	int maxforGrayScaleNumberInTheMatrix;
	bool youCanWrite = false;
	bool toGray = false;
public:

	std::ifstream stream;
	PPM(char const* file) : stream(file)
	{
		input();
		readASCI();
		/*if (youCanWrite)
		{
			writeASCI();
		}*/
		
	}
	void print()
	{
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width*NumberofPixels; j++)
				cout << buf[i][j] << " ";
			cout << endl;
		}
	}

	bool toGrayScale()
	{
		//int placefori = 0;
		temporaryTransformation = new int*[height];
		for (int i = 0; i < height; i++)
			temporaryTransformation[i] = new int[width];
		
		for (int i = 0; i < height; i++)
		{
			for (int j = 0, tempJ = 0; tempJ < width, j < width*NumberofPixels; tempJ++, j += 3)
				temporaryTransformation[i][tempJ] = (buf[i][j] * redCoefficientToGrayScale + buf[i][j + 1] * greenCoefficientToGrayScale + buf[i][j + 2] * blueCoefficientToGrayScale);
		}

		cout << endl;
		cout << endl;
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
				cout << temporaryTransformation[i][j] << " ";
			cout << endl;
		}
		
		maxforGrayScaleNumberInTheMatrix = 0;
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width;j++)
			if (temporaryTransformation[i][j]>maxforGrayScaleNumberInTheMatrix)
			{
				maxforGrayScaleNumberInTheMatrix = temporaryTransformation[i][j];
			}
		}
		cout << endl;
		cout << maxforGrayScaleNumberInTheMatrix << endl;
		youCanWrite = true;
		toGray = true;
		return true;

	}

	void input()
	{
		stream >> x;
		stream >> width;
		stream >> height;
		stream >> MaxPix;
	}


	bool readASCI()
	{
		buf = new int*[height];
		for (int i = 0; i < height; i++)
			buf[i] = new int[width*NumberofPixels];

		for (int i = 0; i < height*NumberofPixels; i++)
		{
			for (int j = 0; j < width*NumberofPixels; j++)
				stream >> buf[i][j];
		}

		return true;
	}

	bool writeGrayScale(const char*output)
	{
		outfile.open(output);
		outfile << "P2" << endl;
		outfile << width << " " << height << endl;
		outfile << maxforGrayScaleNumberInTheMatrix << endl;
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
				outfile << temporaryTransformation[i][j] << " ";
			outfile << endl;
		}

		outfile.close();
		return true;
	}

	
	bool writeASCI(const char*output)
	{
		/*myfile.open("example.txt");
		myfile << "Writing this to a file.\n";
		myfile.close();*/
		outfile.open(output);
		/*outfile << "this is spartaaa" << endl;
		outfile << "fckitTTt" << endl;*/
		//outfile<<

		outfile.close();

		return true;
	}
	

	bool checkIsAlreadyMonochrome()
	{
		if ((strcmp(x, "P1") == 0) || (strcmp(x, "P4") == 0))//x - tittle
			return true;
		else false;
	}
	bool checkIsAlreadyGrayScale()
	{
		if ((strcmp(x, "P2") == 0) || (strcmp(x, "P5") == 0))//x - tittle
			return true;
		else false;
	
	}

	
	bool writeMonochrome(const char*output)
	{
		double delimiter = maxforGrayScaleNumberInTheMatrix / 2;
		
		
		toGrayScale();
		outfile.open(output);
		outfile << "P1" << endl;
		outfile << width << " " << height << endl;
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				if (temporaryTransformation[i][j]>delimiter)
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