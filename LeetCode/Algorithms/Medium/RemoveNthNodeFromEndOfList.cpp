// Method - 1 (Better and Efficient Solution)

// We just need to go to the node before the one to be removed  
// and to maintain the distance n from last we can take two-pointers 
// and maintain the same distance between them, when one reaches null 
// other reaches the required position and gets the job done

// 0 -> [1,2,3,4,5]

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *dummy_head = new ListNode(0);

        dummy_head.next = head;

        ListNode *slow = head;
        ListNode *fast = head;

        for (int i = 0; i <= n + 1; i++)
        {
            fast = fast->next;
        }

        while (fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }

        slow->next = slow->next->next;

        return dummy_head->next;
    }
}
// Time Complexity - O(N)
// Space Complexity - O(1)

// Method - 2
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        int count = 0;
        ListNode *curr = head;
        while (curr != NULL)
        {
            count += 1;
            curr = curr->next;
        }
        if (count <= 1)
        {
            return curr;
        }
        curr = head;
        int node_no = count - n + 1; // Node position from the end (5 - 2 = 3)
        if (count == n)
        {
            while (node_no--)
            {
                curr = curr->next;
            }
            return curr;
        }
        for (int i = 1; i < node_no - 1; i++)
        { // 0, 1, 2
            // cout<<i<<" "<<endl;
            curr = curr->next;
            cout << curr->val << " ";
        }
        curr->next = curr->next->next;
        return head;
    }
};