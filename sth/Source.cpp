#include<iostream>
#include<fstream>
using namespace std;

struct Student
{
	char name[64];
	double score;   //sreden uspeh


};

bool read(const char*file, int position, Student& s)       
{
	ifstream in(file, ios::in | ios::binary); 
	
	if (!in.is_open())
	{
		return false;
	}
	int size = sizeof(s);
	in.seekg(0, ios::end); 
	int total = in.tellg();

	if (position*size >= total)
	{
		in.close();
		return false;
	}
	
    in.seekg(position*size, ios::beg); 
	 
	in.read(reinterpret_cast<char*>(&s), size);

	in.close();
	return true;
}

bool write(const char*file, Student s)
{
	ofstream out(file, ios::out| ios::app);//
	if (!out.is_open())  
	{
		return false;
	}
	int size = sizeof(s);
	//out.write((const char*)&s, size); //davame adresa na s    // (reinterpret_cast<const char*>(&s) , size);
	out.write(reinterpret_cast<const char*>(&s), size);

		
	//out.seekp(n, ios::beg);
	//cout << out.tellp() << endl;

	out.close();

	return true;
}

bool update(const char*file, Student s)
{
	ifstream in(file, ios::in | ios::binary);    
	ofstream out(file, ios::out | ios::binary | ios::app);   
	if (!in.is_open() || !out.is_open())
	{
		if (out.is_open())
		{
			out.close();
		}
		if (in.is_open())
		{
			in.close();
		}
		return false;
	}

	in.seekg(0, ios::beg); 
	int size = sizeof(s);
	int position = 0;
	Student cur;
	while (in.eof()) 
	{
		in.seekg(size*position, ios::beg);
		in.read(reinterpret_cast<char*>(&cur), size);
		if (in.eof())
		{
			in.close();
			out.close();
			return false;
		}
		if (!strcmp(cur.name, s.name))
		{
			out.seekp(position*size, ios::beg);
			out.write(reinterpret_cast<const char*>(&s), size);
			in.close();
			out.close();
		
			return true;
		}
		position++;
	}
	in.close();
	out.close();
	return false;
}

bool del(const char*file, int position);

int main()
{
	Student s;
//	s.name = "dsasda";
	strcpy_s(s.name, "First"); //annyoing....
	s.score = 20;
	const char*file = "students.db";
	write(file, s);
	//out.tellp();  kazva ni poziciqta
	//tellg() ? 
	//seekp(); // za 4etene 
	//seekg();
	
	Student p;
	Student z;

	strcpy_s(z.name, "Second");
	z.score = 10;

	write(file, z);

	read(file, 1, p);

	Student q;
	strcpy_s(q.name, "Second");
	q.score = 5;

	update(file, q);



	cout << p.name << endl;
	cout << p.score << endl;
	cout << endl;
	cout << z.score << endl;
	

	getchar();
	return 0;
}