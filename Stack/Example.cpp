#include<iostream>
#include "SSS.h"
using namespace std;
int main()
{
    Stack S;
    int var;
    CreateStack(&S);
    push(20 , &S);
    pop(&var ,&S);
    cout<<"POP here: "<<var<<endl;
    return 0;
}


