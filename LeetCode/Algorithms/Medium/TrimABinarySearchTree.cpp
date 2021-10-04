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
class Solution
{
public:
    TreeNode *trimBST(TreeNode *root, int low, int high)
    {
        if (root == NULL)
            return NULL;

        // when the root doesn't lie within the range
        if (root->val > high)
            return trimBST(root->left, low, high);
        else if (root->val < low)
            return trimBST(root->right, low, high);

        // when the root is within the specific range
        // assign left and right to root
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);

        return root;
    }
};

// Time Complexity - O(N)
// Space Complexity - O(N), implicit stact takes in N elements