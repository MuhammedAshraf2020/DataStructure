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
    int pop()
    {
        // If Stack is not Empty this Function pop from Stack
        // return Element NotEmpty
        // return NULL Empty
        if(!StackEmpty())
    {
        StackNode *Temp;
        StackEntry e = top->entry;
        Temp = top;
        top = top->next;
        free(Temp);
        --size;
        return e;
    }
    else
        return NULL;
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