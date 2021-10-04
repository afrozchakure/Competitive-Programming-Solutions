class MyStack 
{
    StackNode top;
    
    //Function to push an integer into the stack.
    void push(int a) 
    {
        StackNode newNode = new StackNode(a);
        // Add your code here
        if(top == null)
            top = newNode; 
        else 
        {
            StackNode temp = top; 
            top = newNode; 
            newNode.next = temp; 
        }
    }
    
    public boolean isEmpty()
    {
        if(top == null)
            return true; 
        else 
            return false;
    }
    //Function to remove an item from top of the stack.
    int pop() 
    {
        // Add your code here
        int popped = -1; 
        if(top  != null)
        {
            popped = top.data; 
            top = top.next;
        }
        return popped; 
    }
}


// Time Complexity - O(1), for inserting element in Linkedlist
// Space Complexity - O(1)
