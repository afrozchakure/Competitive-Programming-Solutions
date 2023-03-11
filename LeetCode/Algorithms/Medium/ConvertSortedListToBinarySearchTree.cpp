class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL) return NULL; 

        if(head->next == NULL) return NULL; 

        ListNode *slow = head, *fast = head, prev = NULL; 

        while(fast != NULL && fast->next != NULL) {
            prev = slow; 
            fast = fast->next->next; 
            slow = slow->next; 
        }

        prev->next = NULL; 

        ListNode *root = new TreeNode(slow->next); 
        root->left = sortedListToBST(head); 
        root->right = sortedListToBST(slow->next);
        return root; 
    }
};

Input: head = [-10,   -3,    0,    5,  9]
                       prev  slow       fast 

// prev->next = NULL; 

// ListNode *root = new TreeNode(slow->next)
// root->left = head; 
// root->right = slow->next; 
// Output: [0,-3,9,-10,null,5]