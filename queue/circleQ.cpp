#include<iostream>
using namespace std;

class CircularQueue
{
private:
	int*arr;
	int size;
	int capacity;
	int front;
	int rear;
	void resize()
	{
		int counter = 0;
		int*temp = new int[capacity * 2];
		for (int i = front; i < size; i++)
			temp[counter++] = arr[i];

		if (counter != size)
		{
			for (int i = 0; i < size - counter; i++)
				temp[counter + i - 1] = arr[i];
		}
		delete arr;
		arr = temp;
		capacity = 2 * capacity;
	}

public:
	CircularQueue(int capacity = 4)
	{
		this->capacity = capacity;
		arr = new int[capacity];
		size = 0;
		front = 0;
		rear = size;
	}
	void print()
	{
		for (int i = 0; i < size; i++)
			cout << arr[((front+i)%capacity)] << " ";
		cout << endl;
		cout << "rear->" << rear << "  size-> " << size << endl;
	}
	void Enqueue(int element)
	{
		size++;
	
		if (size>capacity)
		{
			resize();
		}
		if (rear==0)
			arr[rear++] = element;
		else
		{
			
			arr[(rear%capacity)] = element;
			rear++;
		}

	}
	void Dequeue()
	{
		if (front == rear)
			; // throw excpetion;
		else
		{
			front++;
			size--;
		}
	}

	void printrear()
	{
		cout << endl;
		cout << rear << endl;
	}
	int Front()
	{
		return arr[front];
	}
	~CircularQueue()
	{
		delete arr;
	}

};
int main()
{
	
	const int FixSize=6;
	CircularQueue q(4);
	q.Enqueue(3);
	q.Enqueue(2);
	q.Enqueue(5);
	q.Enqueue(6);
	q.Enqueue(7);
	q.Enqueue(9);
	q.Dequeue();
	q.Enqueue(10);
	
	/*int x[FixSize];
	for (int i = 0; i < FixSize; i++)
	{
		x[i] = q.Front();
		q.Dequeue();
	}

	for (int i = 0; i < FixSize; i++)
		cout << x[i] << " ";
	cout << endl;
*/

	q.print();

	getchar();
	return 0;
}