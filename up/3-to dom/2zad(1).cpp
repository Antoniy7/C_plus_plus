#include<iostream>
using namespace std;
int main()
{
	int n, a[1025]; int c[1025] = { 0, };
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	int br = 0;
	int max2 = 0;
	int position1 = 0; int q = 0; int e[1025];
	for (int i = 1; i <= n; i++)
	{

		if (a[i] == a[i + 1])
		{

			c[a[i]]++; br++; e[q] = i;
			q++;
		}
		if (a[i] != a[i + 1])
		{
			if (br > max2)
			{
				max2 = br; position1 = e[0];
				br = 0; q = 0;
			}

		}
	}
	if (position1==0) cout<<"nqma ploshtadka"<<endl;
	else cout << position1 << " " << max2 + 1 << endl;

	return 0;
}
