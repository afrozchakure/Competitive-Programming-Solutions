// Iterative solution (Using Stack)
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
    int rangeSumBST(TreeNode *root, int L, int R)
    {
        int rangeSum = 0;
        stack<TreeNode *> s;
        s.push(root);
        while (!s.empty())
        {
            TreeNode *temp = s.top();
            s.pop();

            if (temp->val >= L && temp->val <= R)
                rangeSum += temp->val;
            if (temp->val > L && temp->left != NULL)
                s.push(temp->left);
            if (temp->val < R && temp->right != NULL)
                s.push(temp->right);
        }
        return rangeSum;
    }
};

// Using Recursion and Traversal (Remember to declare sum globally in private and set sum to zero within the starter function)
// DFS Solution (Inorder)
class Solution
{

public:
    int sum; // Here the sum will get updated after helper function gets executed
    int rangeSumBST(TreeNode *root, int L, int R)
    {
        sum = 0;
        helper(root, L, R);
        return sum;
    }
    void helper(TreeNode *root, int L, int R)
    {
        if (root == NULL)
            return;

        helper(root->left, L, R);
        if (root->val >= L && root->val <= R)
            sum += root->val;
        helper(root->right, L, R);
    }
};

// Time Complexity - O(N), where N is the height of the tree
// Space Complexity - O(H), where H is the height of the tree (recursive call stack)