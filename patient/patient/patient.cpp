#include<cstring>
#include"patient.h"
using namespace std;


Patient::Patient(const char*name, const char*egn) : name(NULL)
{
	size_t l = strlen(name) + 1;          //this->SetName(name);
	//this->name = name;
	this->name = new char[l];
	strcpy_s(this->name, l, name);
	strcpy_s(this->egn, 11, egn);
}

Patient::Patient(const Patient& other) :name(NULL)
{
	//this->name = "";
	/*size_t l = strlen(name) + 1;
	this->name = new char[l];
	strcpy_s(this->name, l, other.name);*/
	this->setName(other.name);
	strcpy_s(this->egn, 11, other.egn);

}

void Patient::setName(const char*name)
{
	size_t l = strlen(name) + 1;
	delete[] this->name;
	this->name = new char[l];
	strcpy_s(this->name, l, name);
}
void Patient::setEgn(const char * egn)
{
	strcpy_s(this->name, 11, egn);
}


Patient::~Patient()
{
	delete[] this->name;
}

Patient& Patient::operator=(const Patient& right)
{

	if (this == &right) return *this; 

	this->setName(right.name);
	strcpy_s(this->egn, 11, right.egn);
	return *this; //stoinost
}

bool Patient::writeToBinary(const Patient& p, ofstream& out)
{
	if (!out) return false;

	int length = strlen(p.name);


	out.write((const char*)&length, sizeof(length)); 
	out.write(p.name, sizeof(char)*length);
	out.write(p.egn, sizeof(egn));
	return out.good();

}

bool readFromBinary(ifstream &in, Patient &p)//kude sht e prenesem informaciqta v pacienta 
{
	if (!in) return false;

	int length;
	in.read((char*)& length, sizeof(length));

	char * temp = new char[length + 1];   
	in.read(temp, sizeof(char)*length); 
	temp[length] = '\0';  
	p.setName(temp);
	char egn[11];
	in.read(egn, sizeof(egn));
	p.setEgn(egn); 

	delete[] temp;

	return in.good();    
}


bool Patient::operator==(const Patient& right)const
{
	return strcmp(egn, right.egn) ==0;
}
