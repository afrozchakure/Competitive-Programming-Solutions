// Using the bottom-up approach, where the value from the leaf node is incremented till the root node 
class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        else
        {
            int left = maxDepth(root->left);
            int right = maxDepth(root->right);

            if (left > right)
                return left + 1;
            else
                return right + 1;
        }
    }
}

// Time Complexity - O(n) - n is the number of nodes in the binary tree
// Space Complexity - O(n) - Since only recursive function call stack is used, n refers to the maximum number of recursive calls we can make (in case of a skew binary tree)
