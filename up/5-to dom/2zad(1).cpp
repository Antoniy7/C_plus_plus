#include<iostream>
using namespace std;
int a[1000];
int n,p=0,q=0;
int c[1000];
void rec()
{
	if (p == n) return;
	else
	{
		if (a[p] % 2 == 0)
		{
			c[q] = a[p];
			q++;
		}
			p++;
		rec();
	}
}
int main()
{
	cin >> n;


	for (int i = 0; i < n; i++)
		cin >> a[i];
	rec();

	cout << endl;
	for (int i = 0; i < q; i++)
		cout << c[i]<<" ";
	cout << endl;
	//system("pause");

	return 0;
}
