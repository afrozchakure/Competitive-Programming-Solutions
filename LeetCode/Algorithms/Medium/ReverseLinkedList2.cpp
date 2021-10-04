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
    ListNode *reverseBetween(ListNode *head, int m, int n)
    {

        if (head == NULL)
            return NULL;

        ListNode *current_node = head;
        ListNode *prev = NULL;
        while (m > 1)
        {
            prev = current_node;
            current_node = current_node->next;
            m--;
            n--;
        }

        ListNode *connection = prev;
        ListNode *tail = current_node;

        while (n > 0)
        {
            ListNode *future = current_node->next;
            current_node->next = prev;
            prev = current_node;
            current_node = future;
            n--;
        }

        if (connection != NULL)
        {
            connection->next = prev;
        }
        else
        {
            head = prev;
        }

        tail->next = current_node;

        return head;
    }
};

// Time Complexity - O(N)
// Space Complexity - O(1)