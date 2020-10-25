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
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;
        else{
            int left = minDepth(root->left);
            int right = minDepth(root->right);
            
            if(min(left, right))
                return min(left, right) + 1;
            else
                return max(left, right) + 1;
        }
    }
};

// Using Ternary Operator (Same technique without else statement
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;
            int left = minDepth(root->left);
            int right = minDepth(root->right);
            
            return 1 + (min(right, left) ? min(right, left) : max(right, left));
    }
};

// Space Complexity - O(1) -> there is no additional data structure used other than recursive call stack
// Time Complexity - O(n) -> n is the number of nodes in binary tree
