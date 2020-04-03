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


void CreateStack( Stack *ps )
{
    // This Function to make initialization for the stack
    // param: Stack address
    //return: Void   
    ps->top = NULL ;
    ps->size = 0;
}

void push(StackEntry e , Stack *ps)
{

    // This Function to push element into the stack : pre condition : Stack Not Full
    // param: value of element which you want to push , adress of Stack
    // return:1 when mession get suc 
    // return:0 when mission get Faild

    StackNode *pn ;
    pn->entry = e;
     pn->next = ps->top;
    ps->top = pn;
    ps->size += 1; 
}

int StackEmpty(Stack *ps)
{
    // This Function to check if the Stack is Empty or Not
    // param: Stack's address
    //return: 1 when stack is Empty
    //return: 0 when stack is Not Empty
    return ps->size == 0; 
}
int StackTop(StackEntry *pe , Stack *ps )

{
    //This Function to show (not pop) the top element of ths stack
    //param : address of element  , address of stack
    //return: 1 if mission is suc
    //return: 0 if mission is faild

    if(!StackEmpty(ps))
    {
        *pe = ps->top->entry;
        return 1;
    }
    else
    {
        return 0;
    }
}

int StackFull(Stack *ps)
{
    // This Function always return Stack is not Full 
    // param : address of the stack
    // return: always return 0
    return 0;
}

int pop(StackEntry *pe , Stack *ps)
{
    // This Function To Pop From Stack Under Concept of LIFO
    // Param : address of Element , address of Stack
    // return: 1 when mission get Suc
    // return: 0 when mission get faild

   StackNode *pn = (StackNode*)malloc(sizeof(StackNode));
  *pe = ps->top->entry;
   pn = ps->top;
   ps->top = ps->top->next;
   free(pn);
   ps->size -=1;
  
}

void ClearStack(Stack *ps)
{
    // This Function to clear Stack
    //param : address of stack
    //return: void
  StackNode *pn = ps->top;
  while(pn)
  {
    pn = pn->next;
    free(ps->top);    
    ps->top = pn;
  }
  ps->size = 0;
}
void TraverStack(Stack *ps , void(*pf) (StackEntry))
{
    //This Function to pass every element in the stack in Function
    //param : address of the stack , address of the function
    //return: void
    StackNode *pn = ps->top;
    while(pn)
    {
        (*pf) (ps->top->entry);
        pn = pn->next;
    }

}

int StackSize(Stack *ps)
{
    //This Function to return number of element
    //param :address of Stack
    //return: Number of elements
    return ps->size;
}
