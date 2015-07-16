#include<iostream>
#include"vector.h"
#include"BinaryVector.h"
using namespace std;

int main()
{
	Vector v(5);

	v.fill();
	v.print(); cout << endl;

	cout << v[1] << endl;
	//v.resize(10);
	cout << endl;
	//v.print();
    
	Vector t(10);
	t.fill();
	t.print(); cout << endl;
	v += t;
	v.print();

	cout << endl;
	
	Vector x = t;
	//x.print();
	
	/*Vector test(10);
	test.fill();
	test = t + v;
	test.print();*/
	/*x.print();
	cout << endl;
	x = v + t;
	x.print();
*/
	/*cout << endl;
	t -= v;
	t.print();*/
	/*Vector test(10);
	test.fill();
	test = v - t;
	test.print();*/
	cout << endl;

	/*v *= 2;
	v.print();*/
	/*t /= 2;
	t.print();*/

	//cout << v%t << endl;


	BinaryVector arr;
	cout << sizeof(arr) << endl;
	arr.print();
	cout << endl;
	arr.set(2);
	arr.set(4);
	arr.print();
	arr.clear(4);
	cout << endl;
	arr.print();

	getchar();





	return 0;
}