// Method - 1 (Traversal with Relinking)
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
    TreeNode *curr = new TreeNode(0);
    TreeNode *increasingBST(TreeNode *root)
    {
        TreeNode *ans = curr;
        ans = curr;

        Inorder(root);

        return ans->right;
    }
    void Inorder(TreeNode *node)
    {
        if (node == NULL)
            return;

        Inorder(node->left);

        node->left = NULL;
        curr->right = node;
        curr = node;

        Inorder(node->right);
    }
};

// Time Complexity - O(N), N is the number of nodes in the given tree
// Space Complexity - O(H), H is the height of the given tree
// and the size of the implicit call stack

// Using Extra Space and Inorder Traversal
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
    TreeNode *increasingBST(TreeNode *root)
    {
        vector<int> val;

        Inorder(root, val);
        TreeNode *node = new TreeNode(0);
        TreeNode *curr = node;

        for (int v : val)
        {
            curr->right = new TreeNode(v);
            curr = curr->right;
        }
        return node->right;
    }

    void Inorder(TreeNode *root, vector<int> &val)
    {
        if (root == NULL)
            return;
        Inorder(root->left, val);
        val.push_back(root->val);
        Inorder(root->right, val);
    }
};

// Time Complexity - O(N), N is the number of nodes in the given tree
// Space Complexity - O(N)
