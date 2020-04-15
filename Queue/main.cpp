#include <iostream>
#include "Queue.h"
using namespace std;

int main()
{
    QueueEntry Var;
    Queue Q;
    CreateQueue(&Q);
    cout<<"Does Queue Empty :"<<QueueEmpty(&Q)<<endl;
    EnQueue(20 , &Q);
    cout<<"Does Queue Empty :"<<QueueEmpty(&Q)<<endl;
    DeQueue(&Var , &Q);
    cout<<"The Front Value  :"<<Var<<endl;
    cout<<"Does Queue Empty :"<<QueueEmpty(&Q)<<endl;
    EnQueue(30 , &Q);
    EnQueue(40 , &Q);
    cout<<"Does Queue Empty :"<<QueueEmpty(&Q)<<endl;
    ClearQueue(&Q);
    cout<<"Does Queue Empty :"<<QueueEmpty(&Q)<<endl;

    return 0;
}
