#pragma once

class Employee
{
protected:
	char*egn;
	char*name;
	char* address;
	double salary;
	char*department;
	void del();

protected:
	void set(char*thing, char* &place);
	

protected:
	static int counter;
	//Employee*arr;
	static int size;
	
	
public:
	Employee(char* egn, char*name, char*address, double salary, char*department);
	virtual ~Employee();
	Employee& operator=(const Employee&other);
	Employee(const Employee& other);
	Employee(char*egn, char*name);
	void print();
	Employee() :name(NULL), address(NULL), department(NULL), egn(NULL)
	{
		counter++;
	}
	void set_name(char*);
	void set_egn(char*);
	void set_address(char*);
	void set_salary(double);
	void set_department(char*);

	char* get_name();
	char* get_egn();
	char* get_address();
	double get_salary();
	char* get_department();
	
	void resize_static();
	friend class  Temp;

};