#include<iostream>
#include <stdio.h>
#include<string.h>
using namespace std;
int main()
{

	char a[100][100];
	char seqs[100][100];
	char words[1000];
	int n,m,numbwords;
	cin >> n >> m;
	cin >> numbwords;
	cout << endl;
	bool yes = false;
	for (int i = 0; i < n;i++)
	for (int j = 0; j < m;j++)
		cin >> a[i][j];


	for (int q = 1; q <= numbwords; q++)
	{
		cin >> words;
		getchar();
		int len = strlen(words);
		///////////////////////////////////////////////// row search
		int p = 0;
		int br = 0;
		while (p != n)
		{
			br = 0;
			char temp[1000];
			for (int i = 0; i <= m; i++)
				temp[i] = a[p][i];
			for (int i = 0; i < m;i++)
			if (words[i] == a[p][i])
				br++;
			if (br == len)
			{
				yes=true; break;
			}
				p++;
		}

		   ////////////////////////////////////////////column search
		int p1 = 0;
		int br1 = 0;
		while (p1 != m)
		{
			br1 = 0;
			char temp1[1000];
			for (int i = 0; i <= n; i++)
				temp1[i] = a[i][p1];
			for (int i = 0; i < n;i++)
			if (words[i] == a[i][p1])
				br1++;
			if (br1 == len)
			{
				yes=true; break;
			}

			p1++;
		}
		///////////////////////////////////////////////////// top left- bottom right diagonal

		int br2 = 0;
		int p2 = 0;
		while (p2 != m)
		{
			br2 = 0;
			char temp2[1000];
			for (int i = 0; i <= n; i++)
				temp2[i] = a[i][i];
			for (int i = 0; i < n;i++)
			if (words[i] == a[i][i])
				br2++;
			if (br2 == len)
			{
				yes = true;; break;
			}
			p2++;
		}
		 ///////////////////////////////////////////////////top right - bottom left diagonal;
		int br3 = 0;
		int p3 = 0;
		while (p3 != m)
		{
			br3 = 0;
			char temp3[1000];
			for (int i = 0, j=m-1; i <= n; i++,j--)
				temp3[i] = a[i][j];
			for (int i = 0, j = m-1; i < n; i++, j--)
			if (words[i] == a[i][j])
				br3++;
			if (br3 == len)
			{
				yes=true; break;
			}
			p3++;
		}
		///////////////////////////////////////////////////////bottom left - top right
		int br4 = 0;
		int p4 = 0;
		while (p4 != m)
		{
			br4 = 0;
			char temp4[1000];
			for (int i = 0, j = m - 1; i <= n; i++, j--)
				temp4[i] = a[j][i];
			for (int i = 0, j = m - 1; i < n; i++, j--)
			if (words[i] == a[j][i])
				br4++;
			if (br4 == len)
			{
				yes=true; break;
			}
			p4++;
		}
                         /////////////// bottom right - top left
		int br5 = 0;
		int p5 = 0;
		while (p5 != m)
		{
			br5 = 0;
			char temp5[1000];
			for (int i = 0, j = m - 1; i <= n; i++, j--)
				temp5[i] = a[j][j];
			for (int i = 0, j = m - 1; i < n; i++, j--)
			if (words[i] == a[j][i])
				br5++;
			if (br5 == len)
			{
				yes=true; break;
			}
			p5++;
		}

		if (yes == true)
		{
			cout << "YES" << endl;
			yes = false;
		}

		//cout << words << endl;
	}

	//system("pause");


	return 0;
}
