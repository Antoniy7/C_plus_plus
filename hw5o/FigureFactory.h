#pragma once
#include<iostream>
#include <fstream>
#include "Triangle.h"
#include "Elipse.h"
#include "Figure.h"
#include "Rectangle.h"


using namespace std;

class FigureFactory 
{
	ifstream inputFile;
	int line;

public:
	FigureFactory()
        {line=0;}

	FigureFactory(const char*file)
         {
               inputFile.open(file);
	       line = 1;
         }
	~FigureFactory()
         {  inputFile.close(); }

	bool canCreate()
        {
         if ((inputFile.is_open()) && (inputFile.good()))
                      return true;
          else false;
        }
	Figure* createFigure()
       {
        char x[10]; 

	inputFile >> x

          if (strcmp(x, "rect") == 0) 
       {
                if (check());
                else break;

		double aX, aY;
		double bX, bY;

		inputFile >> aX;
		inputFile >> aY;
		inputFile >> bX;
		inputFile >> bY;


		line++;

		return new Rectangle(aX, aY, bX, bY);
	}

          else

	   if (strcmp(x, "circle") == 0) 
        {
                if (check());
                else break;

		double x_axis;
		double y_axis;
		double radius;
		inputFile >> x_axis;
		inputFile >> y_axis;
		inputFile >> radius;

		
		line++;

		return new Elipse(x_axis, y_axis radius);
	}
       
	else 
      if (strcmp(x, "triangle") == 0) 
        {
              if (check());
                else break;

		double aX, aY;
		double bX, bY;
		double cX, cY;

		inputFile >> aX;
		inputFile >> aY;
		inputFile >> bX;
		inputFile >> bY;
		inputFile >> cX;
		inputFile >> cY;

		line++;

		return new Triangle(aX, aY, bX, bY, cX, cY);
	}
       

 
       }

bool check()
{
    if (!inputFile) 
   {
	return false;
   }
   else true;
}

	
};
