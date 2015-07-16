#include<iostream>
#include<string.h>
using namespace std;
void IdentifierToUpper(char *a)
{
	bool flag = true;
	int p = 0;
	while (a[p] != '\0')
	{
		if (!((a[p] >= 'a'&& a[p] <= 'z') || (a[p] >= 'A' && a[p] <= 'Z') || (a[p] >= '0' && a[p] <= '9') || a[p]=='_'))
		{
			flag = false; break;
		}
		p++;
	}
	if (flag == true && a[0] != '1' && a[0] != '2' && a[0] != '3' && a[0] != '4' && a[0] != '5' && a[0] != '6' && a[0] != '7' && a[0] != '8' && a[0] != '9' && a[0] != '0')   // i a[0] da e razlichno ot 0,1,2,3,4,5,5,6,7,8,9 inache dava greshka ... x;
	{
		a[0] = a[0] - 'a' + 'A';
		cout << a << endl;;
	}
	else cout << "not an Identifier" << endl;
}
int main()
{
	char test1[100] = { 's', ' ', '4' };

	char test2[100] = { '$', 's', '5', '#' };

	char test3[100] = { '4', 's', 'q' };

	char test4[100] = { 'd','a','t', '_', 'n','a','m','e' };

	char test5[100] = {'n','e','1'};

	cout << "INPUT " << test1 << endl;
	IdentifierToUpper(test1);
	cout << endl;

	cout << "INPUT " << test2 << endl;
	IdentifierToUpper(test2);
	cout << endl;

	cout << "INPUT " << test3 << endl;
	IdentifierToUpper(test3);
	cout << endl;

	cout << "INPUT " << test4 << endl;
	IdentifierToUpper(test4);
	cout << endl;

	cout << "INPUT " << test5 << endl;
	IdentifierToUpper(test5);
	cout << endl;

	//system("pause");

	return 0;
}
