#include<iostream>
using namespace std;

class Queue
{
private:
	int *arr;
	int capacity;
	int size; // v momenta razmera koito ima 
	void resize()
	{
		capacity = size * 2;
		int *temp=new int [size*2];
		for (int i = 0; i < size; i++)
			temp[i] = arr[i];
		delete arr;
		arr = temp;
	}
	
public:
	Queue(int capacity=4)
	{
		this->capacity = capacity;
		arr = new int[capacity];
		size = 0;
	}
	bool Isempty()
	{
		if (size)
		{
			cout << "not empty" << endl;
			return false;
		}
		else
		{
			cout << "empty" << endl;
			return true;
		}
	}
	int Front()
	{
		if (size >= 0)
			return arr[0];
		else
			throw; //exception
	}
	void Dequeue()
	{
		if (size == 0)
		{
			throw exception
		}
		else
		{
			int*temp = new int[size];
			for (int i = 1; i < size; i++)
				temp[i - 1] = arr[i];
			size--;
			delete arr;
			arr = temp;
		}
	}
	void print()
	{
		cout << "[ ";
		for (int i = 0; i < size; i++)
			cout << arr[i] << " ";
		cout << "]" << endl;;
	}
	void Enqueue(int element)
	{
		
		if (size > capacity)
		{
			resize();
		}
		arr[size++] = element;

	}
	~Queue()
	{
		delete arr;
	}

};
int main()
{
	Queue q;
	q.Enqueue(10);
	q.Enqueue(20);

	q.Isempty();
	q.print();
	

	getchar();
	return 0;
}

