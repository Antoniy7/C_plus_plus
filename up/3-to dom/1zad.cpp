#include<iostream>
using namespace std;
int main()
{
	int a[1025];
	int n; double sum = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
		{
		cin >> a[i]; sum += a[i];
		}
	double avr = (sum / n);

	for (int i = 1; i <= n; i++)
	{
		if (a[i] > avr) cout << a[i] << endl;
	}

	return 0;
}
