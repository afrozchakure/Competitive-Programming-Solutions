// By creating another Linked List (Learn this one)
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *temp = new ListNode(0);
        ListNode *current = temp;

        while (l1 != NULL && l2 != NULL)
        {
            if (l1->val < l2->val)
            {
                current->next = l1;
                l1 = l1->next;
            }
            else
            {
                current->next = l2;
                l2 = l2->next;
            }
            current = current->next;
        }
        if (l1 != NULL)
        {
            current->next = l1;
            l1 = l1->next;
        }
        if (l2 != NULL)
        {
            current->next = l2;
            l2 = l2->next;
        }

        return temp->next;
    }
};

// Time Complexity - O(M+N)
// Space Complexity - O(M+N)

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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *curr1 = l1, *curr2 = l2, *temp;
        int flag = 0;
        if (curr1 == NULL || curr2 == NULL)
        {
            if (curr1 == NULL)
                return curr2;
            return curr1;
        }

        if (curr1->val <= curr2->val)
        {
            temp = curr1;
            curr1 = curr1->next;
            flag = 1;
        }
        else
        {
            temp = curr2;
            curr2 = curr2->next;
        }

        while (curr1 != NULL && curr2 != NULL) // when both of them are not NULL
        {
            if (curr1->val <= curr2->val)
            {
                temp->next = curr1;
                temp = curr1;
                curr1 = curr1->next;
            }
            else
            {
                temp->next = curr2;
                temp = curr2;
                curr2 = curr2->next;
            }
        }

        if (curr1 == NULL)
            temp->next = curr2;
        if (curr2 == NULL)
            temp->next = curr1;
        if (flag == 1)
            return l1;
        return l2;
    }
};

// Time Complexity - O(M+N)
// Space Complexity - O(M+N)