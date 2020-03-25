class StackNode
{
 StackEntry entry;
 StackNode *next;
}

class Stack
{
    //Class to Link Nodes togther
    // AND include Accsess mechanism
    // push , pop , StackFull , StackEmpty , size , StackTop ;  
public:
    StackNode *top;
    int size;

public:

    Stack()
    {
        // initialization
        top = NULL ;
        size = 0 ;
    }
    
    void push(StackEntry data )
    {
        //This Function To push into Stack
        //param : Data 
        //return: void

        StackNode *Temp = (StackNode*) malloc(sizeof(StackNode));
        Temp->entry = data;
        Temp->next  = top;
        top = Temp;
        ++size;

    }
    int pop(StackEntry *pe)
    {
        // If Stack is not Empty this Function pop from Stack
        //param: address of variable which you want to save entry in
        // return 1 if mission suc
        // return 0 if mission faild
        if(!StackEmpty())
    {
        StackNode *Temp;
        *pe = top->entry;
        Temp = top;
        top = top->next;
        free(Temp);
        --size;
         return 1;
    }
    else
        return 0;
    }
    int StackEmpty()
    {
        // return if the stack is empty
        return top == NULL;
    }
    
    int StackFull()
    {
        // return 1 forever
        return 1;
    }
    int StackSize()
    {
        // return number of elements
        return size;
    }
    int Peek()
    {
        // return the top element without delete him
        return top->entry; 
    }
};
