#include<iostream>
#include<fstream>
#include<cstring>
#include"Pbm.h"
#include"PGM.h"
#include"PPM.h"
#include<string>
#include"Transformation.h"
using namespace std;

int main(int argc, char *argv[])
{
	bool grayscale = false;
	bool monochrome = false;
	
	bool ppm = false;
	int ppmPosition;
	bool pgm = false;
	int pgmPosition;
	bool pbm = false;
	int pbmPosition;
	int i;//index
//	char*buffer;
	char*pointer=NULL;
	std::cout << "Have " << argc << " arguments:" << std::endl;
	for ( i = 1; i < argc; ++i) 
	{
		//cout << argv[i] << endl;

		if (strcmp((const char*)argv[i], "--grayscale") == 0)
		{
			grayscale = true;
		}
		if (strcmp((const char*)argv[i], "--monochrome") == 0)
		{
			monochrome = true;
		}

		if (string(argv[i]).find("ppm") != std::string::npos) 
		{
			
			cout << argv[i] << endl;
			
			pointer = argv[i];
			cout << pointer;

			ppmPosition = i; ppm = true;

		}
		if (string(argv[i]).find("pgm") != std::string::npos)
		{
			char*x = "picture.pgm";
			PGM*pgmpointer = new PGM(x);
			pgmPosition = i; pgm = true;
		}

		if (string(argv[i]).find("pbm") != std::string::npos)
		{
			pbmPosition = i; pbm = true;
			char*x = "picture.pbm";
			PBM*pbmpointer = new PBM(x);
		}
	}
	
	if (grayscale == true)
	{
		if (ppm == true)
		{
			char*x = "picture.pgm";
			PPM*ppsmpointer = new PPM(pointer);
			//PPM sth(argv[i]);
			//sth.writeGrayScale(x);
			ppsmpointer->toGrayScale();
			ppsmpointer->writeGrayScale(x);
		}
	    
	}




	//getchar();
	return 0;
}