#include<iostream>
#include <fstream>

#include "Point.h"

using namespace std;



int main()
{

	//Point p;
	Point p1(1, 2);
	
	p1.setX(58);

	//getchar();

	ofstream outputFile("Test.txt", ios::out);
	p1.print(outputFile);
	p1.print(cout);

	//cout << p1.getY() << endl;
	getchar();

	p1.test();
	getchar();












	return 0;
}