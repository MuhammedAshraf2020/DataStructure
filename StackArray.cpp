class Stack
{

private:

    StackEntry *arr;
    int top;
    int capacity;

public:
    Stack(int Size)
    {
        // To Make initalization for int top , and Create Stack
        arr = new StackEntry[Size];
        top = 0;
        capacity = Size;
    }
    ~Stack()
    {
        // To Delete Array
        delete arr;
    }

    int push(StackEntry e)
    {
        // Push element into stack
        // param: (defined DataType) element
        //return: 1 if Suc : 0 if faild
        if(!StackFull())
        {
        arr[top++] = e;
        return 1;
        }
        else
            return 0;
    }
    int pop(StackEntry*pe)
    {
        // To Get Element from Stack and move top 
        // param :address of var
        // return:1 if Suc : 0 if Faild
        if(!StackEmpty())
        {
        *pe = arr[--top];
        return 1;
        }
        else
            return 0;
    }
    int StackFull()
    {
        // Function To return 0 if Stack Not Fall : 1 if Stack Full 
        return top == capacity;
    }
    int StackEmpty()
    {
        // Function to return 0 if Stack include elements : 1 if Stack Empty
        return top == 0;
    }
    int StackSize()
    {
        // Function To return Number of Elements in the Stack
        return top;
    }
    int StackTop(StackEntry *pe)
    {
        //Function To return the top element in the stack
        //param : address of StackEntry var
        //return: 1 if mission suc : 0 if mission faild
        if (!StackEmpty())
        {
            *pe = arr[top];
            return 1;
        }
        else
            return 0;
    }
}; 
