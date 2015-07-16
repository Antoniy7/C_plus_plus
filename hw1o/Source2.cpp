//Visual Studio 2013
// C++
#include<iostream>
using namespace std;
int len;
char* caesar_encrypt(char*str, int n)
{
	for (int i = 0; i < len; i++)
	{
		if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
		{
			if (str[i] == 'z' && n != 0) 
				str[i] = 'a' - 1;
			if (str[i] == 'Z' && n != 0)
				str[i] = 'A' - 1;


			str[i] = str[i] + n;
		}
	}
	return str;
}
int main()
{
	int n;
	char x[1024];
	cin >> x;
	cin >> n;
	len = strlen(x);
	cout << caesar_encrypt(x, n) << endl;


	system("pause");
	return 0;
}