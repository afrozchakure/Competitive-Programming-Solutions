// Iterative Solution
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
    int sumOfLeftLeaves(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        int sum_of_left_leaves = 0;

        stack<TreeNode *> s;
        s.push(root);

        while (!s.empty())
        {
            TreeNode *temp = s.top();
            s.pop();
            if (temp->left != NULL)
            {
                if (temp->left->left == NULL && temp->left->right == NULL)
                    sum_of_left_leaves += temp->left->val;
                else
                    s.push(temp->left);
            }
            if (temp->right != NULL)
            {
                if (temp->right->left != NULL || temp->right->right != NULL)
                    s.push(temp->right);
            }
        }
        return sum_of_left_leaves;
    }
};

// Time Complexity - O(n), n is the number of nodes in the binary tree
// Space Complexity - O(n)

// Recursive Solution
class Solution
{
public:
    int sumOfLeftLeaves(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        int sum_of_left_leaves = 0;

        if (root->left != NULL)
        {
            // It means we have reached a left node
            // so we just add the value to sum_of_left_leaves
            if (root->left->left == NULL && root->left->right == NULL)
                sum_of_left_leaves += root->left->val;
            else
            {
                sum_of_left_leaves += sumOfLeftLeaves(root->left);
            }
        }

        // if we find a right node
        // just check if both right side or left side of root->right
        // is not NULL and call the function recursively

        if (root->right != NULL)
        {
            if (root->right->right != NULL || root->right->left != NULL)
                sum_of_left_leaves += sumOfLeftLeaves(root->right);
        }

        return sum_of_left_leaves;
    }
};
