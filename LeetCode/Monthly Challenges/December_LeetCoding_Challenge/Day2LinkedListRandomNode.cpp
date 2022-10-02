// Without using extra space
class Solution
{
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    ListNode *head;
    Solution(ListNode *head)
    {
        this->head = head;
    }

    /** Returns a random node's value. */
    int getRandom()
    {
        int chosenValue = 0;
        int scope = 1;
        ListNode *curr = head;
        while (curr != NULL)
        {
            if (rand() % (scope) < 1.0 / scope)
                chosenValue = curr->val;
            curr = curr->next;
            scope += 1;
        }

        return chosenValue;
    }
};

// Time Complexity - O(N)
// Space Complexity - O(1)

// Using extra space
#include <experimental/random>

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
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    vector<int> result;
    Solution(ListNode *head)
    {

        while (head != NULL)
        {
            result.push_back(head->val);
            head = head->next;
        }
    }

    /** Returns a random node's value. */
    int getRandom()
    {
        int random = rand() % (result.size());

        return result[random];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */

// Time Complexity - O(1) for getRandom() and O(N) for Solution constructor
// Space Complexity - O(N)
