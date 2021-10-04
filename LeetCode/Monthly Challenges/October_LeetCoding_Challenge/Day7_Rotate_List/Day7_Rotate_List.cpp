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
    ListNode *rotateRight(ListNode *head, int k)
    {
        ListNode *temp = head;
        int count = 0;
        if (temp == NULL)
            return head;
        while (temp->next != NULL)
        {
            count += 1;
            temp = temp->next;
        }
        temp->next = head;
        temp = temp->next;
        // cout<<temp->val<<endl;
        ListNode *prev = NULL;
        int remaining = count - (k % (count + 1)) + 1;
        while (remaining--)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        return temp;
    }
};