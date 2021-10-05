/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        
        int counter = 0;
        ListNode *curr = new ListNode(0);
        
        curr->next = list1;
        
        ListNode *prev = list1;
        while(list1 != NULL && counter != a)
        {
            prev = list1;
            list1 = list1->next;
            counter++;
        }
        
        while(counter != b+1)
        {
            list1 = list1->next;
            counter++;
        }
        
        ListNode *temp = list1;
        
        ListNode *current = prev;
        current->next = list2;
        
        while(current->next != NULL)
        {
            current = current->next;
        }
        
        current->next = temp;
        
        return curr->next;
        
    }
};

