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

// Since its a binary search tree, we can traverse it any way we want
class Solution
{
public:
    TreeNode *searchBST(TreeNode *root, int val)
    {
        if (root == NULL)
            return root;
        if (root->val == val)
            return root;
        // if value is on the left side, we go to the left side
        if (val < root->val)
        {
            return searchBST(root->left, val);
        }
        // if value is greater than we move to the right side
        else
        {
            return searchBST(root->right, val);
        }
    }
};

// Time Complexity - O(n)
// Space Complexity - O(n), n is the number of nodes in the binary search tree