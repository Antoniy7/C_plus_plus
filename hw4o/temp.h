#pragma once
//#include"employee.h"
#include"specialist.h"
#include"leader.h"
class Temp : public Leader
{
	friend class Specialist;
	friend class Employee;
	//Employee*arrTemp=new Employee[10];
	
public:
	void add(const Employee&other)
	{
		resize();
		arr[counter - 1] = other;
	}

};