#include <iostream>
using namespace std;

class Singleton
{
private:
	static Singleton* pInstance;
	Singleton();
	Singleton(Singleton const &);
	Singleton& operator=(Singleton const&);

public:
	static Singleton& GetInstance();
	static void Release();
	int Data;
};

Singleton* Singleton::pInstance = NULL;


Singleton::Singleton()
{
}

Singleton::Singleton(Singleton const &)
{
}

Singleton& Singleton::operator=(Singleton const&)
{
	return *this;
}

Singleton& Singleton::GetInstance()
{
	if (pInstance == NULL)
		pInstance = new Singleton;

	return *pInstance;
}

void Singleton::Release()
{
	delete pInstance;
	pInstance = NULL;
}


int main()
{
	Singleton::GetInstance().Data = 100;
	cout << Singleton::GetInstance().Data << endl;
	Singleton::Release();


	getchar();
	return 0;
}