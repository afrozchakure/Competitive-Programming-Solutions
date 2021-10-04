/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL)
            return true; 
        else if(p == NULL || q== NULL)
            return false; 
        else if(p->val != q->val)
            return false;
        
        return isSameTree(p->right, q->right) && isSameTree(p->left, q->left);
    }
};

// Time Complexity - O(N), N is the number of nodes in the tree
// Space Complexity - O(log(N)), best case of completely balanced tree 
// O(N) is the worst case of completely unbalanced tree, to keep recursion stack.  