public class Stack{
    
    private int arr[];
    private int top;
    private int capacity;
    
    // Constractour to initialize The Values
    
    Stack(int size)
    {   
     arr = new int[size];
     capacity = size;
     top = 0;
 
    }
    
    public int Push(int x)
    {
        // Function To push element in Stack
        //param : element 
        //return: 1 if mission Suc: 0 if mission faild
        if(!isFull())
        {
        arr[top++] = x;            
            return 1;
        }
        else
            return 0;
    }

    public boolean isFull()
    {
        //Function To return if Stack is Fall!
        return top == capacity ;
    }
    public boolean isEmpty()
    {
        //Function To return if Stack is Empty
        return top == 0;
    }
    
    public int pop()
    {
        //This Function To return The Top Element
        // Top

        if (!isEmpty())
        {
            return arr[top--];
        }
        else
            System.exit(1);

    }
}
