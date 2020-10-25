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
// Space Complexity - O(1) - Since only recursive function call stack is used