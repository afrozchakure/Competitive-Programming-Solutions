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
class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast != NULL && fast->next != NULL)
        {
            // Here fast gets to the end of list
            // while slow gets to the middle of the list
            fast = fast->next->next;
            slow = slow->next;
        }
        // After slow gets to the middle of the list
        // reverse the list and iterate from
        slow = reversed(slow);
        fast = head;

        // Iterate till slow becomes null
        // if value of slow and fast are different return false
        while (slow != NULL)
        {
            if (slow->val != fast->val)
                return false;
            slow = slow->next;
            fast = fast->next;
        }

        return true;
    }
    ListNode *reversed(ListNode *head)
    {
        ListNode *prev = NULL;
        ListNode *future;
        while (head != NULL)
        {
            future = head->next;
            head->next = prev;
            prev = head;
            head = future;
        }
        return prev;
    }
};

// Time Complexity - O(n)
// Space Complexity - O(1)