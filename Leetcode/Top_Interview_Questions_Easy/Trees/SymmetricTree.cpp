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
    bool helper(TreeNode* root1, TreeNode* root2){
        if(root1== NULL && root2 == NULL) return true;
        if(root1 && root2 && root1->val == root2->val)
            return(helper(root1->left, root2->right) && helper(root1->right, root2->left));
    return false;
    }
    
    bool isSymmetric(TreeNode* root) {
       return helper(root, root);
        }
};

// Time Complexity - O(N) - N is the no. of nodes in the tree
// Space Complexity - O(h) - h is height of the tree
