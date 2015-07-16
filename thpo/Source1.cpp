#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	ifstream file("Test.txt", ios::in);

	

	ofstream output("name.txt", ios::out | ios::binary);

	bool canRead = true;
	if (!file.is_open())
	{
		cout << "error" << endl; return 1;
	}
		double number;

		while (canRead)
		{

			file >> number;
			if (file) // ako sustoqnieto e dobro zna4i e pro4eto normalno  
			{              
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
					file.clear();
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


		file.close();
		output.close();

	return 0;
}



