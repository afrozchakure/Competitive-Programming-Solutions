class Solution {
    public:
        ListNode *reverseLL(ListNode *head) {
            ListNode *curr = head; 
            ListNode *prev = NULL; 
            while(curr != NULL) {
                ListNode *futureNode = curr->next; 
                curr->next = prev; 
                prev = curr; 
                curr = futureNode; 
            }
            return prev; 
        }
        ListNode* reverseKGroup(ListNode* head, int k) {
            ListNode *temp = head; 
            ListNode *prevLast = NULL; 
            
            while(temp != NULL) {
                ListNode *kthNode = getKthNode(temp, k); 
                if(kthNode == NULL) {  // only when List is larger than K
                    if(prevLast != NULL) { 
                        prevLast->next = temp;  
                    }
                    break;
                }
    
                ListNode *nextNode = kthNode->next; 
                kthNode->next = NULL; 
                reverseLL(temp); 
                
                if(temp == head) {
                    head = kthNode; 
                } else {
                    prevLast->next = kthNode; 
                }
    
                prevLast = temp; 
                temp = nextNode; 
            }
            return head;
        }
    
        ListNode *getKthNode(ListNode *temp, int k) {
            k--; 
            while(temp != NULL && k > 0) {
                temp = temp->next; 
                k--;
            }
            return temp; 
        }
};

/*
Time Complexity - O(N)
Space Complexity - O(1)
*/