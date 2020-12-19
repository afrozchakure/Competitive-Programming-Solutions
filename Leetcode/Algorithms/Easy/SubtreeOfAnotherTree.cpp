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
    bool isSubtree(TreeNode *s, TreeNode *t)
    {
        if (s == NULL)
            return false;
        else if (isSameTree(s, t))
            return true;
        else
        {
            return isSubtree(s->left, t) || isSubtree(s->right, t);
        }
    }

    bool isSameTree(TreeNode *s, TreeNode *t)
    {
        if (s == NULL || t == NULL)
        {
            // Important step, cannot return false since we need to check if both values are NULL or only one is NULL
            return s == NULL && t == NULL;
        }
        else if (s->val == t->val)
        {
            return isSameTree(s->left, t->left) && isSameTree(s->right, t->right);
        }
        else
        {
            return false;
        }
    }
};

// Time Complexity - O(m x n), m - no. of nodes in s & n -> no. of nodes is m
// Space Complexity - O(min(m, n)), depends on the numbers of nodes in
// s and t

// Kevin's Solution