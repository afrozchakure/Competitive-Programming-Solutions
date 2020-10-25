// Method - 1 Recursive Method

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
    TreeNode *invertTree(TreeNode *root)
    {
        if (root == NULL)
            return root;

        // Recursive Calls
        invertTree(root->left);
        invertTree(root->right);

        // Swap the pointers
        TreeNode *temp = root->left;
        root->left = root->right;
        root->right = temp;

        return root;
    }
};

// Time Complexity - O(n) -- n is the number of nodes in the tree
// Space Complexity - O(n) -- O(h) function calls will be placed onto the stack, where h is the depth of the binary tree
// O(h) belongs to O(n)

// Another Recursive Solution
class Solution
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        if (root == NULL)
            return NULL;

        // Creating two poionter left and right
        TreeNode *left = invertTree(root->left);
        TreeNode *right = invertTree(root->right);

        // Assigning the left of root to right pointer and right of root to left pointer
        root->left = right;
        root->right = left;

        return root;
    }
};

// Method - 2 Iterative Method
class Solution
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        if (root == NULL)
            return NULL;

        queue<TreeNode *> q;

        q.push(root);
        while (!q.empty())
        {
            TreeNode *current = q.front();
            q.pop();
            TreeNode *temp = current->left;
            current->left = current->right;
            current->right = temp;

            if (current->left != NULL)
                q.push(current->left);
            if (current->right != NULL)
                q.push(current->right);
        }

        return root;
    }
};