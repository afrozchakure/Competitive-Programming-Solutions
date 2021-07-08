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
    int goodNodes(TreeNode* root) {
        int res = dfs(root, root->val);
        return res;
    }
    
    int dfs(TreeNode *root, int maxValue)
    {
        if(root == NULL)
            return 0;
        
        int res;
        if(root->val >= maxValue)
            res = 1;
        else
            res = 0;
        
        maxValue = max(maxValue, root->val);
        
        res += dfs(root->left, maxValue);
        res += dfs(root->right, maxValue);
        
        return res;
    }
};

// Time Complexity - O(N)
// Space Complexity - O(h) / O(logN), h is the height of the tree, and can be as big as O(N), where N is the no. of nodes in the tree
