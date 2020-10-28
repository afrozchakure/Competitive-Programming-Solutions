/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include<bits/stdc++.h>
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL || head->next == NULL) return false;
        
        ListNode *slow = head;
        ListNode *fast = head->next;
        
        while(slow != fast)
        {
            if(fast == NULL || fast->next == NULL) return false;
            slow = slow->next;
            fast = fast->next->next;
        }
        return true;
    }
};

// Time Complexity - O(n) -> n is the length of linked list (when list has no cycle)
// If cycle time complexity - O(N+K) -> which is O(n)
// Space Complexity - O(1) Used only two nodes, so space complexity is O(1)
