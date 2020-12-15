#include <iostream>
using namespace std;
#define MaxQueue 100 
class Queue {
	int size, rear, front, TempQueue, Entry[MaxQueue];
public:
	Queue() {
		this->size = 0;
		this->rear = -1;
		this->front = -1;
		this->TempQueue = 0;
	}
	void EnQueue(int e) {
		rear = (rear + 1) % MaxQueue;
		Entry[rear] = e;
		size = size + 1;
	}
	int DeQueue() {
		TempQueue = (front + 1) % MaxQueue;
		TempQueue = Entry[TempQueue];
		++front;
		--size;
		return TempQueue;
	}
	bool QueueEmpty() {
		return size == 0;
	}
	bool QueueFull() {
		return size == MaxQueue;
	}
	void TraverseQueue(int(*pf)(int))
	{
		TempQueue = (front + 1) % MaxQueue;
		for (int i = 0; ; i++)
		{
			Entry[TempQueue] = pf(Entry[TempQueue]);
			if (TempQueue == rear)
				break;
			TempQueue = (TempQueue + 1) % MaxQueue;

		}
	}
};
int POW(int e)
{
	return pow(e, 2);
}

int main()
{
	Queue MyQueue;

	MyQueue.EnQueue(200);
	MyQueue.EnQueue(300);
	MyQueue.TraverseQueue(&POW);
	cout << MyQueue.DeQueue() << endl;
	cout << MyQueue.DeQueue() << endl;

	return 0;
}
