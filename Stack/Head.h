#define StackEntry int
#define MaxStack 3
#define Linked_Stack

#ifdef Linked_Stack
/************************************************************************************************************************/
/*												LINKED BASED                                                             /
/************************************************************************************************************************/

typedef struct stacknode
{
    StackEntry entry;
    struct stacknode *next;

}StackNode;


typedef struct stack
{
    StackNode *top;
    int size;
}Stack;

#else
/************************************************************************************************************************/
/*												ARRAY BASED                                                              /
/************************************************************************************************************************/

struct stack
{
   StackEntry entry[MaxStack];
   int top;
}Stack;

#endif

void CreateStack( Stack * ) ;

void push(StackEntry  , Stack *);

int StackEmpty(Stack *);

int StackTop(StackEntry * , Stack * );

int StackFull(Stack *);

int pop(StackEntry * , Stack *);

void ClearStack(Stack *);

void TraverStack(Stack * , void(*) (StackEntry));

int StackSize(Stack *);
