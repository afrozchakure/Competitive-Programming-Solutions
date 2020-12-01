// Using extra space
#include<experimental/random>

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
class Solution {
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    vector<int> result;
    Solution(ListNode* head) {
        
        while(head != NULL)
        {
            result.push_back(head->val);
            head = head->next;
        }
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int random = rand() % (result.size());
        
        return result[random];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */