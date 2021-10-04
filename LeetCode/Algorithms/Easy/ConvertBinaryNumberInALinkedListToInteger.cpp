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
    int getDecimalValue(ListNode *head)
    {
        int result = 0;
        while (head)
        {
            result = result * 2 + head->val;
            head = head->next;
        }
        return result;
    }
};

// Time Complexity - O(n)
// Space Complexity - O(1)

// Using Bit Manipulation

class Solution
{
public:
    int getDecimalValue(ListNode *head)
    {
        int result = head->val;
        while (head->next != NULL)
        {
            result = (result << 1) | head->next->val;
            head = head->next;
        }
        return result;
    }
};

// Time Complexity - O(n)
// Space Complexity - O(1)