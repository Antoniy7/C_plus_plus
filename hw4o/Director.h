#pragma once
#include"Secretary.h"
#include"leader.h"
class Director: public Leader
{
private:
	//Employee*arr;
	Secretary secretary;

	Employee** arrEmployees;
	int employee_counter;
	int employee_capacity;
	
	Specialist** arrSpecialists;
	int specialist_counter;
	int specialist_capacity;
	
	
public:

	Director(char*egn, char*name, char*address, double salary, char*department, char*description, char*information) :Leader(egn, name, address, salary, department, description, information)
	{
		set_beginning();
		arrEmployees = NULL;
		arrSpecialists = NULL;
	}
		
	Director() :Leader()
	{
		
	}
	void set_beginning()
	{
		specialist_capacity = 10;
		specialist_counter = 0;
		employee_counter = 0;
		employee_capacity = 10;
	}
	void resizeDIR()
	{
		if (employee_counter >= employee_capacity)
		{
			employee_capacity = employee_capacity * 2;
		}
		if (specialist_counter >= specialist_capacity)
		{
			specialist_capacity = specialist_capacity * 2;
		}
	}
	int getNumberofEmployees() 
	{
		return employee_counter;
	}

	int getNumberofSpecialists() 
	{
		return specialist_counter;
	}


	void addEmployee(Employee* other)
	{
		resizeDIR();

		Employee** temp = new Employee*[employee_capacity];
		
		for (int i = 0; i < employee_counter; i++) 
		{
			temp[i] = arrEmployees[i];
		}
		
		delete[] arrEmployees;

		temp[employee_counter++] = other;
		//resizeDIR();
		
//		for (int i = 0; i < employee_counter; i++) 
//			arrEmployees[i] = temp[i];
		
               arrEmployese=temp;
		
		//delete[] temp;
		
	}
	void addSpecialist(Specialist* other)
	{
		resizeDIR();
		Specialist** temp = new Specialist*[specialist_capacity];

		for (int i = 0; i < specialist_counter; i++)
		{
			temp[i] = arrSpecialists[i];
		}

		//delete[] arrEmployees;

		temp[specialist_counter++] = other;
		//resizeDIR();

		for (int i = 0; i < specialist_counter; i++)
			arrSpecialists[i] = temp[i];

		delete[] temp;

	}

	void setSecretary(Secretary& newSecretary) 
	{
		this->secretary = newSecretary;
	}
	Secretary getSecretary() 
	{
		return secretary;
	}

	Director& operator=(Director& other)
	{
		if (this == &other)
		{
			return *this;
		}
		else
		{
			setSecretary(other.getSecretary());

			employee_counter = other.getNumberofEmployees();
			specialist_counter = other.getNumberofSpecialists();

			employee_capacity = other.employee_capacity;
			specialist_counter = other.specialist_counter;

			arrEmployees = new Employee*[employee_capacity];
			arrSpecialists = new Specialist*[specialist_capacity];

			for (int i = 0, j = 0; i < employee_counter, j < specialist_counter; j++, i++)
			{
				arrEmployees[i] = other.arrEmployees[i];
				arrSpecialists[j] = other.arrSpecialists[j];
			}

		}
	}



};