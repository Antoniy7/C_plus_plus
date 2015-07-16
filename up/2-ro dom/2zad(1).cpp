#include<iostream>
using namespace std;
int isPrime(int x)
{
	if (x == 0) return 0;
	if (x == 1) return 0;
	  else
		{
			bool flag = false;
			for (int i = 2; i*i <= x; i++)
			if (x%i == 0) flag = true;
			if (flag == false) return 1;
			else return 0;
		}
}
int main()
{
	int n, m, sum, br = 0;
	cin >> n >> m;
	for (int i = n; i <= m; i++)
	{
			sum = 0;
			for (int j = 1; j <= m; j++)
				{
					if (i%j == 0 && j != i)
						sum += j;
				}
			if (isPrime(sum))
				br++;
	}

	cout << br << endl;

	return 0;
}
