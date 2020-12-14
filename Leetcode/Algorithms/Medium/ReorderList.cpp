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
    void reorderList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return;

        // Here slow is the head to the list 2
        ListNode *slow = head;

        // Pointer to tail of list 2
        ListNode *fast = head;

        // Pointer to the tail of list 1
        ListNode *prev = NULL;

        ListNode *l1 = head;

        while (fast != NULL && fast->next != NULL)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        prev->next = NULL;

        ListNode *l2 = ReverseList(slow);

        merge(l1, l2);
    }

    void merge(ListNode *l1, ListNode *l2)
    {
        while (l1 != NULL)
        {
            ListNode *l1_next = l1->next;
            ListNode *l2_next = l2->next;

            l1->next = l2;

            if (l1_next == NULL)
                break;

            l2->next = l1_next;
            l1 = l1_next;
            l2 = l2_next;
        }
    }

    ListNode *ReverseList(ListNode *head)
    {
        ListNode *curr = head;
        ListNode *prev = NULL;

        while (curr != NULL)
        {
            ListNode *future = curr->next;
            curr->next = prev;
            prev = curr;
            curr = future;
        }
        return prev;
    }
};