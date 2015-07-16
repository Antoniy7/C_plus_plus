#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	for (int row = 0; row < n; row++)
	{
     int print = 1;
     int mul = row;
     int div = 1;

		  for (int i = 1; i<=n-row; i++)
			  cout << " ";

            for (int j = 0; j<= row; j++)
            {
                cout << " " << print;
                print *= mul;
                print = print / div;
                mul--;
                div++;
            }
    cout << endl;
	}

return 0;
}
