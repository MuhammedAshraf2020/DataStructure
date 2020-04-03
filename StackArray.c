// here we define Data Type of elements in the stack (user mission)
struct stack
{
   StackEntry entry[MaxStack];
   int top;
}Stack;
void CreateStack(Stack *ps)
{
    // This Function to make initialization for the stack
    // param: Stack address
    //return: Void
    ps->top = 0 ;
}

int StackFull(Stack *ps)
{
    // This Function to check if the Stack is Full or Not
    // param: Stack's address
    //return: 1 when stack is Full
    //return: 0 when stack is Not Full

    return ps->top == MaxStack ;
}

int push(StackEntry e , Stack *ps)
{
    // This Function to push element into the stack : pre condition : Stack Not Full
    // param: value of element which you want to push , adress of Stack
    // return:1 when mession get suc 
    // return:0 when mission get Faild

    if(!StackFull(ps))
    {
        ps->entry[ps->top++] = e ;
        return 1;
    }
    else
        return 0;
}

int StackEmpty(Stack *ps)
{

    // This Function to check if the Stack is Empty or Not
    // param: Stack's address
    //return: 1 when stack is Empty
    //return: 0 when stack is Not Empty

   return ps->top == 0;
}

int pop( StackEntry *pe , Stack *ps)
{
    // This Function To Pop From Stack Under Concept of LIFO
    // Param : address of Element , address of Stack
    // return: 1 when mission get Suc
    // return: 0 when mission get faild

    if (!StackEmpty(ps))
    {
        *pe =  ps->entry[--ps->top];
		return 1;
	}
	
	else
		return 0;
}

int StackTop(StackEntry *pe ,  Stack *ps)
{
    //This Function to show (not pop) the top element of ths stack
    //param : address of element  , address of stack
    //return: 1 if mission is suc
    //return: 0 if mission is faild
	if (!StackEmpty(ps)){
		*pe = ps->entry[ps->top-1];
        return 1;
    }
    else
    {
        return 0;
    }
}
int StackSize(Stack *ps)
{
    //This Function to return Number of elements in the stack
    //param : address of Stack
    //return: number of elements
	return ps->top;
}
void ClearStack(Stack *ps){
    // This Function to clear Stack
    //param : address of stack
    //return: void
     ps->top = 0;
}

void TraverseStack(Stack *ps, void (*pvisit)(StackEntry)){
    //This Function to loop Function on evert element of the stack
    //param :address the stack , address the function befored by return type of the function
    //return:void
    for(int i=ps->top; i>0; i--)
        (*pvisit)(ps->entry[i-1]);
}
