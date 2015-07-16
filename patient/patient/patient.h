#ifndef Patient_H
#define Patient_H
#include<fstream>
class Patient
{
private:
	char egn[11];
	char *name; 
public:
	Patient(const char* = "", const char* = "");     


	Patient(const Patient&);	
	Patient& operator=(const Patient&);  
	~Patient();
	void Patient::setName(const char*name);

	void Patient::setEgn(const char*egn);

	const char* getName() const
	{
		return name;
	}
	const char* getEGN()const
	{
		return egn;
	}

	bool writeToBinary(const Patient& p, ofstream& out);
	
	bool operator==(const Patient& right)const;
};
#endif
