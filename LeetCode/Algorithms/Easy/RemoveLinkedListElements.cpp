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
    ListNode *removeElements(ListNode *head, int value)
    {
        ListNode *node_val = new ListNode(0);
        ListNode *curr = node_val;

        curr->next = head;

        ListNode *prev = node_val;

        while (curr != NULL)
        {
            prev = curr;
            curr = curr->next;

            if (curr != NULL && curr->val == value)
            {
                prev->next = curr->next;
                curr = prev;
            }
        }
        return node_val->next;
    }
};