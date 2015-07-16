#include<iostream>
using namespace std;
int main()
{
	int n, a[100][100];
	cin >> n;
	int p = 1;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			a[i][j] = p++;
	}

	int b_row = 1;
	int e_row = n;
	int b_colon = 1;
	int e_colon = n;
	int flag = 1;

	while ((b_row <= e_row) && (b_colon <= e_colon))
	{
		if (flag == 1)
		{
			for (int i = b_colon; i <= e_colon; i++)
			{
				cout << a[b_row][i] << " ";
			}
			flag++; b_row++;
		}
		if (flag == 2)
		{
			for (int i = b_row; i <= e_row; i++)
			{
				cout << a[i][e_colon] << " ";
			}
		  e_colon--;
		  flag++;
		}
		if (flag == 3)
		{
				for (int i = e_colon; i >= b_colon; i--)
				{
					cout << a[e_row][i] << " ";
				}

			flag++;
			e_row--;
		}
		if (flag == 4)
		{
			for (int i = e_row; i >= b_row; i--)
			{
				cout << a[i][b_colon] << " ";
			}
			flag = 1;
			b_colon++;
		}
	}

	cout << endl;
	return 0;
}
