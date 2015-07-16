#ifndef Circle_H
#define Circle_H

#include"Point.h"

class Circle
{
public:
	Circle();
	Circle(const Point&, double);
	Circle(double, double, double);
	Circle getCenter()const; // return ? 
	double getRadisu()const;
	void setCenter(const Point&);
	void setRadius(double);

	



private:
	Point center;
	double r;
};








#endif