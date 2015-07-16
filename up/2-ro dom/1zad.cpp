#include<iostream>
using namespace std;

void Odd(int n);
void Even(int n);
void bottom(int n);

int main()
{
	int n;
	cin >> n;
	if (n % 2 == 0) Even(n);
	else Odd(n);


	return 0;
}
void Odd(int n)
{
       bool flag = false;
		 int n1;
		n1 = ((n + 1) / 2);
		for (int row = 1; row <= n; row++)
		{
			 for (int i = 1; i <= n - row; i++)
					cout << " ";

					if (flag == false)
					{
						cout << n1; flag = true;
					}
						else
						{
							for (int i = n1 - row + 1; i <= n1 + row - 1; i++)
								cout << i;

							if (row == n1) break;
						}
			 cout << endl;
		}
		cout << endl;

		bottom(n);

		for (int i = 1; i <= n - 1; i++)
			 cout << " ";
		cout << n1 << endl;
}
void Even(int n)
{

		int n1 = (n / 2) + 1;
		bool flag = false;
		for (int row = 1; row <= n; row++)
		{
				for (int i = 1; i <= n - row; i++)
					cout << " ";

				    if (flag == false)
					{
						cout << n / 2 << n1; flag = true;
					}
						else
						{
							for (int i = (n / 2) - row + 1; i <= n1 + row - 1; i++)
								cout << i;
							if ((n / 2) == row) break;
						}
		    cout << endl;
		}
		cout << endl;

		for (int i = 1; i <= n / 2; i++)
			cout << " ";

		for (int i = 1; i <= n; i++)
			cout << i;

		cout << endl;

		bottom(n);

		for (int i = 1; i <= n - 1; i++)
			cout << " ";

		cout << n / 2 << n1 << endl;
}

void bottom(int n)
{
	int n2 = ((n + 1) / 2);
	int beg = 2; int end = n - 1;
		for (int i = n - n2 + 1; i < n - 1; i++)
		{
			for (int q = n - i; q < n; ++q)
				cout << " ";

			for (int z = beg; z <= end; z++)
				cout << z;

			++beg; --end;
			cout << endl;
		}
}
