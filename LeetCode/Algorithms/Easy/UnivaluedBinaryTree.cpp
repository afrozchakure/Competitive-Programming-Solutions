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
    bool isUnivalTree(TreeNode *root)
    {
        stack<TreeNode *> s;
        s.push(root);
        int flag = 0;
        int compare = root->val;
        while (!s.empty())
        {
            TreeNode *temp = s.top();
            s.pop();
            if (temp->val != compare)
                return false;

            if (temp->left != NULL)
                s.push(temp->left);

            if (temp->right != NULL)
                s.push(temp->right);
        }
        return true;
    }
};

// Time Complexity - O(N), N is the number of nodes in the given tree
// Space Complexity - O(N, Maximum number of node in the stack at a time

// Using Recursion

class Solution
{
public:
    bool isUnivalTree(TreeNode *root)
    {
        // Here null will be considered as True value
        bool left_univalued = root->left == NULL || root->left->val == root->val && isUnivalTree(root->left);
        bool right_univalued = root->right == NULL || root->right->val == root->val && isUnivalTree(root->right);

        // We can do && also between the two subtrees
        return left_univalued == right_univalued;
    }
};

// Time Complexity - O(n), n is the number of nodes in the binary tree
// Space Complexity - O(h), where h is the height of the binary tree