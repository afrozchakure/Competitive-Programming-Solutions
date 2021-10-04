/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution
{
public:
    TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned, TreeNode *target)
    {
        cloned = find(target, cloned);
        return cloned;
    }

    TreeNode *find(TreeNode *target, TreeNode *cloned)
    {
        if (cloned == NULL)
            return cloned;

        if (cloned->val == target->val)
            return cloned;

        TreeNode *left = find(target, cloned->left);
        TreeNode *right = find(target, cloned->right);

        return (left != NULL) ? left : right;
    }
};

// Time Complexity - O(N)
// Space Complexity - O(1)