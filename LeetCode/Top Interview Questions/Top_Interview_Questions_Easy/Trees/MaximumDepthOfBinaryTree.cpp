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
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        else{
            int count_left = maxDepth(root->left);
            int count_right = maxDepth(root->right);
            if(count_right > count_left)
                return count_right+1;
            return count_left+1;
        }
    }
};

// Time Complexity - O(n) // n is the no. of nodes in the Binary Tree
