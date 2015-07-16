#pragma once

class Triangle : public Figure
{
	double aX;
	double aY;
	double bX;
	double bY;
	double cX;
	double cY;

public:
	Triangle()
	{
		aX = bX = cX = aY = bY = cY = 0;
	}
	Triangle(double x1, double y1, double x2, double y2, double x3, double y3)
	{
		aX = x1;
		aY = y1;
		bX = x2;
		bY = y2;
		cX = x3;
		bY = y3;
	}
	
	virtual ~Triangle();

	bool isPointInFigure(double x1, double y1)
	{
		double AB = (y1 - aY)*(bX - aX) - (x1 - aX)*(bY - aY);
		double CA = (y1 - cY)*(aX - cX) - (x1 - cX)*(aY - cY);
		double BC = (y1 - bY)*(cX - bX) - (x1 - bX)*(cY - bY);

		if (((AB*BC) > 0) && ((BC*CA) > 0))
			return true;
		else
			return  false;
	}
	

	
};


