#include"Point.h"
	
Point::Point(double x, double y)      
{
	this->x = x;
	this->y = y;
	this->print(cout);
	cout << "was created"<<endl;
}

Point :: ~Point()
{
	this->print(cout);
	cout << "was destroyed" << endl;;
}

void Point::setX(double x)
{
	this->x = x;
}
void Point::setY(double y)
{
	this->y = y;
}
void Point::print(ostream& out)const
{
	out << x << " " << y << endl;
}
void Point::test()
{
	cout << x << endl;
}