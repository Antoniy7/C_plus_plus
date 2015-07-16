#include<iostream>
#include<fstream>
using namespace std;

struct Client
{
	char IBAN[23];
	char name[20];
	double balance;
	//char* name;
	//name = new char[]
};
	bool readFromBinary(ifstream & , Client&); 
	bool storeInBinary(ofstream &, const Client &);
	bool readFromText(ifstream &, Client &);
	bool storeInText(ofstream &, const Client &);

	bool readFromBinary(ifstream& in, Client&cl)
	{
		in.read((char*)&cl, sizeof(Client));
		return in.good();       
	}

	bool storeInBinary(ofstream& out, Client&cl)
	{
		out.write((char*)&cl, sizeof(Client));
		return out.good();       
	}

	bool readFromText(ifstream &in, Client&cl)
	{
		in >> cl.IBAN >> cl.name >> cl.balance;
		return in.good();
	}


int main()
{

	ifstream in("name", ios::in | ios::binary);
	Client cl;
	strcpy(cl.IBAN, "12341");
	cl.IBAN = "dsa";//static memory 
	cl.balance = 4;

	while (readFromBinary(in, cl))
	{
		storeInText(inputTextFile,cl)  // inputtextfile e text file 
	}



	return 0;
}



