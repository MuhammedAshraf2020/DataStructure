#pragma once
#define StackEntry int
#define MaxStack 200

#define linkedStack

#ifdef linkedStack

class Node{
public:
	StackEntry Data;
	Node* next;
};

class Stack{
public:
	Node* head;
	StackEntry TempData;
	Stack();
	void push(StackEntry);
	StackEntry pop();
	StackEntry peek();
	int StackEmpty();
	int StackFull();
	//TODO ThroughStack
};

#else


class Stack {
public:
	int top;
	StackEntry Temp;
	StackEntry Arr[MaxStack];

public:
	Stack();
	void push(StackEntry e);
	StackEntry pop();
	StackEntry peek();
	int StackFull();
	int StackEmpty();
	int StackSize();
	void ClearStack();
	void ThroughStack(StackEntry(*pf)(StackEntry));
};


#endif // linkedStack
