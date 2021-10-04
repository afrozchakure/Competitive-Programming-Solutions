bool isCircular(Node *head)
{
   // Your code here
   if(head == NULL)
        return true;
   Node *node = head->next; 
   
   while(node != NULL && node != head)
   {
       node = node->next;
   }
   
   return (head == node);
}

// Time Complexity - O(N)
// Space Complexity - O(1)
