bool detectLoop(Node* head)
{
    // your code here
    Node *slow = head; 
    Node *fast = head; 
    // slow = slow->next; 
    // head = fast->next->next; 
    
    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next; 
        fast = fast->next->next;
        if(fast == slow)
        {
            return true;
        }
    }
    return false;
}
 
// Time Complexity - O(N) 
// Space Complexity - O(1)   
    
