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
    ListNode *swapNodes(ListNode *head, int k)
    {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode *node = new ListNode(0);
        node->next = head;
        ListNode *current = node;

        ListNode *fast = node->next;

        int count = 0;

        while (fast != NULL)
        {
            fast = fast->next;
            count++;
        }
        int remaining = count - k;

        cout << "Count :" << count << endl;
        cout << "Remaining :" << remaining << endl;

        // first half
        ListNode *prev1 = node->next;
        ListNode *prev2 = node->next;

        ListNode *first = node->next;
        ListNode *slow = node->next;

        k -= 1;

        if (remaining - k == 1)
        {
            while (k-- && first != NULL)
            {
                prev1 = first;
                first = first->next;
            }

            // second half;
            while (remaining-- && slow != NULL)
            {
                prev2 = slow;
                slow = slow->next;
            }

            prev1->next = slow;

            ListNode *temp = slow->next;
            slow->next = first;
            first->next = slow->next;
            return node->next;
        }

        while (k-- && first != NULL)
        {
            prev1 = first;
            first = first->next;
        }

        // second half;
        while (remaining-- && slow != NULL)
        {
            prev2 = slow;
            slow = slow->next;
        }

        prev1->next = slow;

        ListNode *temp = slow->next;

        slow->next = first->next;

        prev2->next = first;
        first->next = temp;

        return node->next;
    }
};

