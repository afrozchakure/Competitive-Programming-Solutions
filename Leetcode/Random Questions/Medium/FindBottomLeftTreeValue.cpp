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
    int findBottomLeftValue(TreeNode *root)
    {
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            root = q.front();
            q.pop();
            if (root->right != NULL)
                q.push(root->right);
            if (root->left != NULL)
                q.push(root->left);
        }
        return root->val;
    };

    // When we traversing the binary tree, we will first push the value of right node into the queue
    // and then the value of the left node
    // It'll allow us to return the left-most node when the queue return empty == True

    // Time Complexity - O(n) - BFS
    // Space Complexity - O(n) - Used queue for traversal