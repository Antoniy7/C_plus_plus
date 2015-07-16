#include<iostream>
using namespace std;
char found[100];
void smallestsubstring(char*x)
{

	int p = 0;
	int br = 0;
	int max = -1;
	while (x[p] != '\n')
	{

		if (x[p] <= 'z' && x[p] >= 'a')
		{
			if (x[p] + 1 == x[p + 1])
			{
				br++;
			}
			if (x[p] + 1 != x[p + 1])
			{
				if (br > max)
				{
					max = br;
					br = 0;
				}
			}

		}

	}
	cout << max << endl;

	
}

int main()
{
  
	char x[100];
	cin >> x;
	
	smallestsubstring(x);
	
	int d;
	//cin >> d;

	return 0;
}