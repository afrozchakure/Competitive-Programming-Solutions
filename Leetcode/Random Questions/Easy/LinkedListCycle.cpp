/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <bits/stdc++.h>
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        LinkedList *slow, *fast;
        slow = head;
        fast = head;
        if (head == NULL || head->next == NULL)
            return false;

        while (slow && fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
            {
                return true;
            }
        }

        return fast;
    }
};

// Time Complexity - O(n) -> n is the length of linked list (when list has no cycle)
// If cycle time complexity - O(N+K) -> which is O(n)
// Space Complexity - O(1) Used only two nodes, so space complexity is O(1)