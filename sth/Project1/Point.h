#ifndef Point_H
#define Point_H
#include<iostream>
using namespace std;

class Point
{
public:
	
	Point(double = 0, double = 0);
	~ Point(); 
	double getX()const;
	void test();
	double getY()const;
	void setX(double);
	void setY(double);
	void print(ostream&) const;  
	double getDist(const Point&) const;

private:
	double x, y;
};

inline double Point::getY() const
{
	return y;
}


#endif
