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
    int number_of_nodes;
    int diameterOfBinaryTree(TreeNode *root)
    {
        number_of_nodes = 1;
        callhelper(root);

        return number_of_nodes - 1;
    }

    int callhelper(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        int left = callhelper(root->left);
        int right = callhelper(root->right);

        number_of_nodes = max(left + right + 1, number_of_nodes);
        return max(left, right) + 1;
    }
};

// Time Complexity - O(n)
// Space Complexity - O(1)