#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	ifstream file("Test.txt", ios::in);



	ofstream output("name.bin", ios::out | ios::binary);

	bool canRead = true;
	if (!file.is_open())
	{
		cout << "error" << endl; return 1;
	}
	double number;

	while (canRead)
	{

		file >> number;
		if (file) 
			output.write((const char*)&number, sizeof(double));        

		}
		else
		{
			if (file.eof())
			{
				cout << "end of file!" << endl;
				canRead = false;
			}
			else  // fail 3
			{
				file.clear();//4istim sustoqnieto na potoka
				char c;
				while (file.get(c) && c != '\t')
				{
					if (!file)
					{
						cout << "end of file reached while ignoring the current number or sth like that ... ;x" << endl;
						canRead = false;
					}
				}
			}
		}

	}

	ifstream file1("name.bin", ios::in | ios::binary);

	if (!file1.is_open())
	{
		return 1;
	}
	double number1;
	while (file1)
	{
		file1.read((char*)&number1, sizeof(double));

		if (file1 && file1.gcount() == sizeof(double))  
			cout << number1 << endl;
	}




	getchar();




	//file.close();
	//output.close();
	file1.close(); 
	return 0;
}



