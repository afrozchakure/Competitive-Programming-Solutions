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
    vector<int> largestValues(TreeNode *root)
    {
        vector<int> largest_val;
        helper(root, largest_val, 0);

        return largest_val;
    }

    void helper(TreeNode *root, vector<int> largest_val, int height)
    {
        if (root == NULL)
            return root;

        if (largest_val.size() == height)
            largest_val.push_back(root->val);
        else
            largest_val[height] = max(largest_val[height], root->val);

        helper(root->left, largest_val, int height + 1);
        helper(root->right, largest_val, int height + 1);
    }
};