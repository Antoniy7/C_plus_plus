#pragma once


class Rectangle 
{
	double aX;
	double aY;
	double bX;
	double bY;

public:
	Rectangle()
	{
		aX = aY = bX = bY = 0;
	}
	Rectangle(double X1, double Y1, double X2, double Y2)
	{
		aX = X1;
		aY = Y1;
		bX = X2;
		bY = Y2;
	}
	virtual ~Rectangle();

	bool isPointInFigure(double cX, double cY)
	{
		if (cX >= aX && cX <= bX && cY <= bY && cY >= aY)
			return true;
		else false;
	}
	

};


