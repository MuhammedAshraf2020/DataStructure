#define ListMax 100
#define ListEntry int
#define ListLink
#ifdef ListLink

typedef struct node
{
    ListEntry data;
    node*next;

}Node;
typedef struct list
{

    Node*Head;
    int Size;

}List;


#else
typedef struct list
{
    ListEntry arr[ListMax];
    int Size;

}List;

#endif
void CreateList(List *);
int Push(int , ListEntry , List*);
int ListEmpty(List *);
int ListFull(List *);
int pop(int , ListEntry* ,List *);
void TravelList( void(*)(ListEntry) , List*);
void  ClearList(List*);
