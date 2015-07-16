#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int n;
int br = 0;
double fill_tetrahedron(double num)
{
	num = num*num*num;
	double q = num / (6 * (sqrt(2)));
	return q / 1000;
}
double tetrahedron_filled(int*a, int water)
{
	for (int i = 0; i < n;i++)
	if (fill_tetrahedron(a[i]) <= water)
		br++;
	return br;
}
int main()
{
	int a[1024];
	//int n;
	int water;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cin >> water;
	 
	cout << tetrahedron_filled(a, water) << endl;


	system("pause");
	return 0;
}