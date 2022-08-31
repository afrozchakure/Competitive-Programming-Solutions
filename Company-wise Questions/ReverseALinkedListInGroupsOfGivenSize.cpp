class Solution
{
    public:
    struct node *reverse (struct node *head, int k)
    { 
        // Complete this method
        struct node *current = head; 
        struct node *future_head = head; 
        struct node *prev = NULL; 
        int count = 0;
        while(current != NULL && count < k) {
            future_head = current->next; 
            current->next = prev; 
            prev = current; 
            current = future_head;
            count++; 
        }
        if(current != NULL) {
            // Here it is important to send the next element of head, 
            // since the starting k elements are already reversed, so the next of head will point 
            // to the starting element of the next k nodes
            // therefore it should be head->next and not current->next
            head->next = reverse(current, k); 
        }
        
        return prev;
        
    }
};

// Time Complexity - O(N)
// Auxillary Space Complexity - O(N/k) : for each linkedlist of size n 
// n/k or n/k + 1 calls will be made