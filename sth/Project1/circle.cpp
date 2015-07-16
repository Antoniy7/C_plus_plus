#pragma once
#include"Circle.h"

Circle::Circle()
{
	r = 0;
}
Circle::Circle(const Point& p, double r) :center(p),r(0)   
{
	//center = p; //this->center 
	this->r = (r > 0) ? r : 0;   // this->setRadisu(r);

}
Circle::Circle(double x, double y, double r)
{
	center.setX(x);
	center.setY(y);
	this->r = (r > 0) ? r : 0;
}
void Circle::setRadius(double r)
{
	if (r > 0)
		this->r = r;
}
void Circle::setCenter(const Point&p)
{
	center = p;
}


