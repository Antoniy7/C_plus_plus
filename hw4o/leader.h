#pragma once 
#include"specialist.h"
#include<cstring>
class Leader : public Specialist
{
	char*information;

public :
	
protected:
	Employee**arr;
        int list_counter;
	//Employee*list;

	void resize()
	{
		if (counter > size)
		{
			Employee*temp = new Employee[size * 2];
			for (int i = 0; i < counter - 1; i++)
			{
				temp[i].set_address(arr[i].get_address());
				temp[i].set_department(arr[i].get_department());
				temp[i].set_egn(arr[i].get_egn());
				temp[i].set_salary(arr[i].get_salary());
				temp[i].set_name(arr[i].get_name());
			}
			delete[] arr;
			arr = temp;
		}
	}
public:

	Leader(char*egn, char*name, char*address, double salary, char*department, char*description, char*information) : Specialist(egn, name, address, salary, department, description)
	{
		set(information, this->information);
		arr = NULL;
	}
	Leader() :Specialist(), information(NULL)
	{

	}
	virtual ~Leader()
	{
		delete information;
	}


	void add(Employee &right)
	{
		resize();
		arr[counter - 1] = *this;
	}
	
	void employee_list()
	{
		resize();
		for (int i = 0; i < counter; i++)
		{
			if (strcmp(arr[i].get_department(), this->get_department()) == 0)
			{
				list[list_counter] = *this;
				list_counter++;
			}
		}
	}

	Leader& operator=(const Leader &right)
	{

		if (this == &right)
			return *this;

		set(right.description, this->description);
		set(right.egn, this->egn);
		set(right.name, this->name);
		set(right.address, this->address);
		set(right.department, this->department);
		this->salary = salary;
		set(right.information, this->information);

		return *this;
	}

	Leader::Leader(const Leader &other)
	{
		set(other.egn, this->egn);
		set(other.name, this->name);
		set(other.address, this->address);
		set(other.department, this->department);
		this->salary = other.salary;
		set(other.description, this->description);
		set(other.information, this->information);
	}


};

