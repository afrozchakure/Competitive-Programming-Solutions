/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *temp1 = headA;
        ListNode *temp2 = headB;
        if(temp1 == NULL || temp2 == NULL)
            return NULL;
        while(temp1 != NULL && temp2 != NULL && temp1 != temp2)
        {
            temp1 = temp1->next;
            temp2 = temp2->next;
            
            
            if(temp1 == temp2)
                return temp1;
            // When temp1 and temp2 become NULL, assign them to the head of each other
            // After each hit NULL, they will be equidistant to target
            if(temp1 == NULL) temp1 = headB;
            if(temp2 == NULL) temp2 = headA;
        }
        return temp1;
    }
};

// Time Complexity - O(n1 + n2)
// Space Complexity - O(n1 + n2)
