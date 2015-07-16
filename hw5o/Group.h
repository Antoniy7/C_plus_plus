#pragma once 
#include"figure.h"
class Group :public Figure
{
	Figure** arrFig;
	int snumberFigures;

public:
			Group();
			 virtual ~Group();
		
};
