#include <iostream>
#include "Stack.h"
using namespace std;

int main()
{
    Stack S;
    int pop_here;
    CreateStack(&S);
    push(20 , &S);
    cout<<"Does Stack empty: "<<StackEmpty(&S)<<endl;
    pop(&pop_here , &S);
    cout << "Top Element in The Stack "<<pop_here << endl;
    cout<<"Does Stack empty: "<<StackEmpty(&S)<<endl;
    return 0;
}
