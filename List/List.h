#include <iostream>
#include "Head.h"
using namespace std;
#define ListLinke
#ifdef ListLinke

void CreateList(List *pl)
{
    pl->Size = 0;
    pl->Head = NULL;
}
int Push(int p  , ListEntry e , List*pl)
{
    if(p<=pl->Size)
    {
    Node*pe = (Node*) malloc(sizeof(Node));
    pe->data= e;
    if(pl->Size == 0)
    {
        pe->next = NULL;
        pl->Head = pe;
    }
    else
    {

    Node*ps = pl->Head;
    for(int i = 0; i<p-1 ;i++)
    { ps = ps->next; }
    pe->next = ps->next;
    ps->next = pe;
    }
    ++pl->Size;
    return 1;
    }
    return 0;
}
int ListEmpty(List *pl)
{
    return pl->Size == 0;
}
int ListFull(List *pl)
{
    return 0;
}
int pop(int p , ListEntry*pe ,List *pl)
{
    //Function to pop from list
    //param : position , pointer to variable, pointer to List
    //return: 1 if mission suc , 0 if mission faild
    if(p <= pl->Size && !ListEmpty(pl))
    {

        Node*ps = pl->Head;
        if(pl->Size == 1)
        {
            *pe = pl->Head->data;
            free(pl->Head);
        }
        else
        {

        for(int i = 0 ; i<p-1; i++)
        {
            ps = ps->next;
        }
        Node*pq = ps->next;
        ps->next = pq->next;
        *pe = pq->data;
        free(pq);
        }
        --pl->Size;
        return 1;
    }
    return 0;

}
void TravelList( void(*pf)(ListEntry) , List*pl)
{
    Node *ps = pl->Head;
 for(int i = 0 ; i<pl->Size ; i++)
 {
     (pf)(ps->data);
     ps = ps->next;
 }

}
void  ClearList(List*pl)
{
    //Function TO CLEAR LIST
    if(pl->Size != 0)
    {
        Node*po = pl->Head->next;
        while(pl->Head->next)
        {
            free(pl->Head);
            pl->Head = po;
            po = po->next;
        }
        free(pl->Head);
        }
}


#else

void CreateList(List *pl)
{
    //Function To initialize List
    pl->Size = 0;

}
int Push(int p , ListEntry e , List *pl)
{
//Function to push element in p position
//param :position , element , list
//return:1 if mission suc , 0 if mission faild

if(!ListFull(pl) && p<= pl->Size)
 {
    for(int i = pl->Size ; i>p ; i--)
 {
     pl->arr[i] = pl->arr[i+1];
 }

 pl->arr[p] = e;
 ++pl->Size;
 return 1;

 }
 return 0;

}

int ListFull(List *pl)
{
    //function to return 1 if  List Full : 0 if Not Full
    return pl->Size == ListMax;

}

int ListEmpty(List *pl)
{
    //Function to return  1 if List Empty , 0 if List include element
    return pl->Size == 0;
}
int Pop(int p , ListEntry*pv , List * pl)
{
    //Function to pop from List
    //param : position , pointer to variable , List
    //return: 1 if mission Suc , 0 if mission faild
    if(!ListEmpty(pl))
    {
        *pv = pl->arr[p];
        for(int i = p ; i<pl->Size ; i++)
        {
            pl->arr[i] = pl->arr[i+1];

        }
        --pl->Size;
        return 1;
    }
    return 0;

}
void ClearList(List*pl)
{
    //Function to reinitialize List
    pl->Size = 0;

}
void TravelList( void(*pf)(ListEntry) , List*pl)
{
    //Function to Pass every Element as a parameter of a passed function
    for(int i = 0 ; i<pl->Size ; i++)
    {
        (pf)(pl->arr[i]);
    }

}
#endif // ListLinke
