#include<iostream>
#include "Stack.cpp"
using namespace std;

int main()
{
	Stack MyStack;
	for (int i = 0; i <= 20; i++)
	{
		if (!MyStack.StackFull())
			MyStack.push(i);
	}


	for (int i = 0; i <= 20; i++)
	{
		if (!MyStack.StackEmpty())
			cout << "Element = " << MyStack.pop() << endl;
	}
	return 0;
}

