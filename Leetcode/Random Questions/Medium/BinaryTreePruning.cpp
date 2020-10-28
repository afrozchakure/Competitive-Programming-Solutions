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
    TreeNode *pruneTree(TreeNode *root)
    {
        return containsOne(root) ? root : NULL;
    }

    // To check whether the root node contains 1 and if not it will prune (remove) that node
    bool containsOne(TreeNode *root)
    {
        if (root == NULL)
            return false;

        bool left_subtree = containsOne(root->left);
        bool right_subtree = containsOne(root->right)

                                 if (!left_subtree)
                                     root->left = NULL;
        if (!right_subtree)
            root->right = NULL;
        return left_subtree || right_subtree || root->val == 1;
    }
};

// Time Complexity - O(n) -> n is the number of nodes in the binary tree
// Space Complexity - O(h) - where h is the height of the binary tree and the size of implicit recurisive call stack