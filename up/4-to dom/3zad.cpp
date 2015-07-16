#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
int main()
{
	char **buffer;
	int n;
	cin >> n;
	char seqs[100][100];
	for (int i = 0; i < n; i++)
	{
		cin >> seqs[i];
		getchar();
	}
	char g[1000];
	cin.get(g, 1000);

	buffer = new char*[n];
	int addedWordsSoFar = 0;

	char *pch;
	pch = strtok(g, " ,.-");
	while (pch != NULL)
	{
		for (int i = 0; i <= n; i++)
		{
			if ((strcmp(pch, seqs[i]) == 0))
			{
				int len = strlen(seqs[i]);
				buffer[addedWordsSoFar++] = new char[len + 1];

				for (int k1 = len - 1, k2 = 0; k1 >= 0, k2 <= len; k1--, k2++)
				{
					buffer[addedWordsSoFar - 1][k2] = pch[k1];
				}
			}
		}
		pch = strtok(NULL, " ,.-");
	}
	for (int i = 0; i < addedWordsSoFar; i++)
	{
		cout << buffer[i] << " ";
		delete buffer[i];
	}
	delete buffer;


	return 0;
}
