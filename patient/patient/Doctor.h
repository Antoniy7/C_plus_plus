#ifndef DOCTOR_H
#define DOCTOR_H

#include"patient.h"
class Doctor
{
private:   
	char*name;
	
	Patient * list; 
	size_t count;
	size_t capacity;


public:
	Doctor(const char*name, size_t capacity); 
	Doctor(const Doctor&);
	Doctor& operator=(const Doctor&);
	~Doctor();
	void setName(const char*);
	const char* getName()const;
	void addPatient(const Patient&p);
	void removePatient(const Patient&p);
	void searchPatients(bool (*pred)(const Patient&)); 
	
	Doctor& operator +=(const Patient& right); 

	int findPatient(const Patient& p); 


};
#endif
