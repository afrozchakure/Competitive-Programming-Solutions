
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
#include <bits/stdc++.h>
class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        std::stack<int> s;
        ListNode *temp = head;
        while (temp != NULL)
        {
            s.push(temp->val);
            temp = temp->next;
        }
        while (head != NULL)
        {
            int i = s.top();
            if (head->val != i)
                return false;
            s.pop();
            head = head->next;
        }
        return true;
    }
};