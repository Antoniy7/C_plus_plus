#include<iostream>
using namespace std;
int n; int p = 1; int q;
int z = 1;
int x=1;
int y;
int t=0;
bool flag1 = true;
void printNum() //ascending
{
	if (z == p) { cout <<z << endl; return; }
	else cout << z;
	z++;
	printNum();
}
void printNum1()//descending
{
	if (z == 1) { cout << x << endl; return; }
	else cout << x;
	z--; x++;
	printNum1();
}
void recBackwards()
{
	if (q == 2)
	{
		t--;
		z = n + t;
		x = 1;
		printNum1();
		return;
	}
	else
	{
		t--;
		z = n + t;
		x = 1;
		printNum1();
	}
	q--;
	recBackwards();
}
void recForward()
{
	if (n == p)
	{
		z = 1;
		printNum();
		recBackwards();
		return;
	}
	else
	{
		z = 1;
		printNum();
	}

	p++;
	recForward();
}

int main()
{
	cin >> n;
	q = n;

	recForward();

	//system("pause");

	return 0;
}
