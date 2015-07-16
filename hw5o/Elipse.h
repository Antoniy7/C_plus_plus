#pragma once

class Elipse
{

	double x_axis;
	double y_axis;
	double radius;
public:
	Elipse()
	{
		this->x_axis = 0;
		this->y_axis = 0;
		this->radius = 0;
	}
	Elipse(double x, double y, double r)
	{
		this->x_axis = x;
		this->y_axis = y;
		this->radius = r;

	}
	/*Elipse(const Elipse& other)
	{
			this->x_axis=other.x_axis;
			this->y_axis = other.y_axis;
			this->radius = other.radius;

	}*/
	/*Elipse& operator=(const Elipse& other)
	{
		if (this == &other) return;
		else
		{
			this->x_axis = other.x_axis;
			this->y_axis = other.y_axis;
			this->radius = other.radius;
		}
	}*/
	virtual ~Elipse();
	
	bool checkPointInFigure(double x, double y)
	{
		double temp = (x - x_axis)*(x - x_axis) + (y - y_axis)*(y - y_axis) <= (radius * radius);
		if (temp)
			return true;
		else false;

	}
 
};