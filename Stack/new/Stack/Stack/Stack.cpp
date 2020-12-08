#include "Stack.h"
#include <iostream>

#ifdef linkedStack

inline Stack::Stack() {
	Node* head = NULL;
}
inline void Stack::push(StackEntry e) {
	Node* newNode = new Node;
	newNode->Data = e;
	newNode->next = head;
	head = newNode;
}
inline StackEntry Stack::pop() {
	Node* Temp = new Node;
	Temp = head;
	head = head->next;
	TempData = Temp->Data;
	delete Temp;
	return TempData;
}
inline StackEntry Stack::peek() {

	return head->Data;
}
inline int Stack::StackEmpty() {
	return head == NULL;
}
inline int Stack::StackFull() {
	return 0;
}


#else

inline Stack::Stack() {
	this->top = 0;
}
inline void Stack::push(StackEntry e) {
	this->Arr[this->top++] = e;
}
inline StackEntry Stack::pop() {
	Temp = this->Arr[--this->top];
	return Temp;
}
inline StackEntry Stack::peek() {
	return this->Arr[this->top];
}
inline int Stack::StackFull() {
	return this->top == MaxStack - 1;
}
inline int Stack::StackEmpty() {
	return this->top == 0;
}
inline int Stack::StackSize() {
	return this->top;
}
inline void Stack::ClearStack() {
	this->top = 0;
}

inline void Stack::ThroughStack(StackEntry(*pf) (StackEntry)) {
	for (int i = this->top - 1; i > 0; i--) {
		this->Temp = (pf)(this->Arr[i]);
		this->Arr[i] = Temp;
	}
}



#endif