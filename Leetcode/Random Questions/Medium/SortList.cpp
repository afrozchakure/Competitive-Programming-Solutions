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
    ListNode *sortList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *temp = head;
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != NULL && fast->next != NULL)
        {
            temp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        temp->next = NULL;

        ListNode *left_side = sortList(head);
        ListNode *right_side = sortList(slow);

        return mergeSort(left_side, right_side);
    }
    ListNode *mergeSort(ListNode *l1, ListNode *l2)
    {
        ListNode *sorted_list = new ListNode(0);
        ListNode *current_node = sorted_list;

        while (l1 != NULL && l2 != NULL)
        {
            if (l1->val > l2->val)
            {
                current_node->next = l2;
                l2 = l2->next;
            }
            else
            {
                current_node->next = l1;
                l1 = l1->next;
            }
            current_node = current_node->next;
        }
        if (l1 != NULL)
        {
            current_node->next = l1;
            l1 = l1->next;
        }
        else
        {
            current_node->next = l2;
            l2 = l2->next;
        }

        return sorted_list->next;
    }
};

// Time Complexity - O(nlogn), where n is number of nodes in the linked list
// Since it uses devide and conquer
// Space Complexity - O(logn), where n is the number of nodes in linked list
// Maximum depth of the recursion tree is logn