#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
int number_of_elemnts;
int size;
bool flag1 = false;
//Cars*car_realloc;
char info[4][50] = { "Lambordgini Murcielago", "Mercedes-AMG", "Pagani Zonda R", "Bugatti Veyron" };
struct  Cars
{
	char name[24];
	int identificaiton_number;
	int registration_number;
};

void save(const char*file, Cars * car,int size)
{
	ofstream out(file, ios::out | ios::app);
	if (!out.is_open())
	{
		return;
	}
	
	for (int i = 0; i < number_of_elemnts; i++)
	out.write((const char*)(&car[i]), size);
	out.close();
}

void loadfrombinary(const char*file, Cars* cars)
{

	ifstream in(file, ios::in | ios::binary);
	in.seekg(0, ios::end);
	int length = in.tellg();

	if (length == 0)
	{
		return;
	}
	if (!in)  
	  return;

	if (!in.is_open())
	{
		cout << "cannot open file"<<endl;
		return;
	}
	in.seekg(0, ios::beg);
	for (int i = 0; i < number_of_elemnts;i++)
		in.read(reinterpret_cast<char*>(&(cars[i])), size);

	in.close();
}

void add(int reg, int ident, char* name, Cars * car)
{
	for (int i = 0; i < number_of_elemnts; i++)
	{
		if (reg == car[i].registration_number)
		{
			cout << "error" << endl;
			return;
		}
	}
	//strcpy((car[number_of_elemnts + 1].name), name);
	car[number_of_elemnts + 1].identificaiton_number = ident;
	flag1 = true;
	/*car_realloc = new Cars[number_of_elemnts + 1];
	Cars *tmp = realloc(car, size);
	copy(car, car_realloc); 
	delete[] car;
	car = temp;*/

}
int carPower(int x)
{
	if (x == 0) return 670;
	if (x == 1) return 503;
	if (x == 2) return 740;
	if (x == 3) return 1020;
}

void generate(Cars*car)
{
	ofstream file("car-report.txt", ios::out);
	int arr[4]; //ot 0 do 3 
	int p = 0;
	if (flag1) 
		p = 1;
	int temp = 0;
	for (int i = 0; i < number_of_elemnts + p; i++)
	{
		temp = car[i].identificaiton_number;
		arr[temp]++;
	}
		
	int max1 = 0;
	int total_cars = 0;
	for (int i = 0; i < 4; i++)
	{
		total_cars += arr[i];
		if (arr[i]>max1)
			max1 = arr[i];
	}
	char* most_popular_car = info[max1];

	if (!file)
	{
		return;
	}

	file << most_popular_car;
	file << endl;

	int  Lambpower = 670;
	int  mercedes = 503;
	int  Pagani = 740;
	int  Bugatti = 1020;

	int aver_power = ((arr[0]*Lambpower + arr[1]*mercedes+arr[2]*Pagani+arr[3]*Bugatti)/total_cars);

	file << aver_power << endl;
	int value;

	for (int i = 0; i < number_of_elemnts + p; i++)
	{
		value = 0;
		value += carPower(car[i].identificaiton_number);
		for (int j = i; j < number_of_elemnts + 1; j++)
		{
			if (strcmp(car[i].name, car[j].name) == 0)
			{
				value += carPower(car[j].identificaiton_number);
			}
		}
		file << car[i].name << " " << value << endl;
	}
}

int main()
{
	Cars c;
	const char*file = "name.db";
	size = sizeof(c);
	ifstream in("test.txt", ios::in | ios::binary);
	in.seekg(0,ios::end); 
	int total = in.tellg();
	in.close();
	number_of_elemnts = (total / size);
	Cars * car = new Cars[number_of_elemnts+1];

	Cars c1;
	int c1_reg = 1;
	char c1_name[10] = "name";
	int c1_ident = 1;
	add(c1_reg,c1_ident,c1_name,car);

	save(file, car,size);
	
	generate(car);

	getchar();

	delete[] car;
	return 0;
}
