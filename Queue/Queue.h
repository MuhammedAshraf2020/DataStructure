#include <stdio.h>
#include <stdlib.h>

#include "Head.h"
#define Linked_Queue

#ifdef Linked_Queue

void CreateQueue(Queue*pq)
{
	// This Function to initialize Queue
	// param : Adress of The Queue
	// return: void
	pq->front = NULL ;
	pq->rear  = NULL;
	pq->size  = 0 ;

}


int EnQueue(QueueEntry e , Queue*pq)
{
	// This Function to Add elements in Queue
	// param : element which you want to enter
	// return: 1 if mission suc : 0 if mission field
	Node *pn = (Node*)malloc(sizeof(Node));
	pn->data = e;
	pn->next = NULL;
	if(QueueEmpty(pq))
    {

        pq->front = pn;
        pq->rear = pn;
        ++pq->size;

    }
    else
    {
        pq->rear->next = pn;
        pq->rear = pn;
        ++pq->size;
    }
}


int DeQueue(QueueEntry *pe , Queue *pq )
{
	//This Function to Get The First element in the Queue
	//param : address of Queue , Address of variable which you want to store in
	//return:1 if mission Suc  , 0 if the mission faild
    if(!QueueEmpty(pq))
    {

    *pe = pq->front->data;
    Node*ps = pq->front;
    pq->front = pq->front->next;
    free(ps);
    --pq->size;
    return 1;
    }

    else
    {return 0;}
}

int QueueFull(Queue *pq)
{
	//This Function allways return 0
    return 0;
}

int QueueEmpty(Queue *pq)
{
	//This Function to return if the Queue if Empty
    return pq->size == 0;
}

void ReverseQueue( Queue *pq , void(*pf)(QueueEntry) )
{
	for(int s = 0; s<pq->size ; s++)
	{
	    Node *ps = pq->front;
		(*pf)(ps->data);
		ps = ps->next;
    }
}


void ClearQueue(Queue*pq)
{
	//This Function To Clear Queue
	if(!QueueEmpty(pq))
	{
	 pq->rear = pq->front->next;
	 while(pq->rear)
     {
        free(pq->front);
        pq->front = pq->rear;
        pq->rear = pq->rear->next;
     }
     free(pq->front);
     pq->size = 0;

	}
}
#else
void CreateQueue(Queue*pq)
{
	// This Function to initialize Queue
	// param : Adress of The Queue
	// return: void
	pq->front = 0 ;
	pq->rear  = -1;
	pq->size  = 0 ;

}


int EnQueue(QueueEntry e , Queue*pq)
{
	// This Function to Add elements in Queue
	// param : element which you want to enter
	// return: 1 if mission suc : 0 if mission field
	if (!QueueFull(pq)){

	pq->rear = (pq->rear+1) % MaxSize;
	pq->arr[pq->rear] = e;
	++pq->size;
	return 1;
	                   }
	else
	{return 0;}
}


int DeQueue(QueueEntry *pe , Queue *pq )
{
	//This Function to Get The First element in the Queue
	//param : address of Queue , Address of variable which you want to store in
	//return:1 if mission Suc  , 0 if the mission faild
    if(!QueueFull(pq))
    {
    *pe = pq->arr[pq->front];
    pq->front = (pq->front+1) % MaxSize ;
    --pq->size;
    return 1;}

    else
    {return 0;}
}

int QueueFull(Queue *pq)
{
	//This Function to return if the Queue if Full
    return pq->size == 0;
}

int QueueEmpty(Queue *pq)
{
	//This Function to return if the Queue if Empty
    return pq->size == MaxSize - 1;
}

void ReverseQueue( Queue *pq , void(*pf)(QueueEntry) )
{
	for(int i = pq->front , int s = 0; s<pq->size ; s++)
	{
		(*pf)(pq->arr[i]);
		i = (i+1) % MaxSize;

	}

void ClearQueue(Queue*pq)
{
	//This Function To Clear Queue
	pq->front = 0 ;
	pq->rear  = -1;
	pq->size  = 0 ;
}
}
#endif
