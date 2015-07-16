#include<iostream>
#include"patient.h"
using namespace std;


int main()
{


	Patient p1("dsa", "2832");
	Patient p2 = p1;
	p2.setName("daaas");

	cout << p2.getName() << endl;

	getchar();






	return 0;
}