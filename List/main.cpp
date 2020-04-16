#include <iostream>
#include "List.h"
using namespace std;

int main()
{
    List L;
    int Var;
    CreateList(&L);
    cout<<"Does List Empty: "<<ListEmpty(&L)<<endl;
    Push(0 , 2 , &L);
    cout<<"Does List Empty: "<<ListEmpty(&L)<<endl;
    pop(0 , &Var , &L);
    cout<<"Value of Var is: "<<Var<<endl;
    Push(0 , 3 , &L);
    Push(1 , 20 , &L);
    ClearList(&L);



}
