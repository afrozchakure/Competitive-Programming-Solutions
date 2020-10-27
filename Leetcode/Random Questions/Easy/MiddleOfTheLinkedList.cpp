// Using slow and fast poitner

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
    ListNode *middleNode(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};

// Time Complexity - O(n)
// Space Complexity - O(1), space used by slow and fast

// Using mid element

class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        int count = 0;
        ListNode *temp = head;
        while (temp)
        {
            count += 1;
            temp = temp->next;
        }
        int mid;
        mid = count / 2 + 1;
        temp = head;
        for (int i = 0; i < mid - 1; i++)
        {
            temp = temp->next;
        }
        return temp;
    }
};

// Space Complexity - O(n)
// Space Complexity - O(1)