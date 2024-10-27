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
    string smallestFromLeaf(TreeNode* root) {
        return helper(root, "");       
    }

    string helper(TreeNode *root, string curr) {
        if(root == NULL) {
            return ""; 
        }

        curr = (root->val + 'a') + curr; 

        if(root->left && root->right) {
            return min(helper(root->left, curr), helper(root->right, curr)); 
        }

        if(root->right) {
            return helper(root->right, curr); 
        }

        if(root->left) {
            return helper(root->left, curr); 
        }
    }
};

// Time Complexity - O(N * N), since we're visiting every node and performing insertion of root->val, n times. 
// Time Complexity - O(N), space used for implicit stack