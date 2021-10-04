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
    bool isCompleteTree(TreeNode *root)
    {
        queue<TreeNode *> q;
        q.push(root);
        bool end_flag = false;
        while (!q.empty())
        {
            TreeNode *temp = q.front();
            q.pop();
            if (temp == NULL)
                end_flag = true;
            // if the value is not NULL
            else
            {
                // We we encountered a NULL value before, return false
                if (end_flag)
                    return false;
                // Push the other values into the queue;
                q.push(temp->left);
                q.push(temp->right);
            }
        }
        return true;
    }
};

// Time Complexity - O(N) -> N is the number of nodes in the binary tree (Since we are traversing each node in tree)
// Space Complexity - O(N) -> N is no. of nodes in the binary tree, All nodes are stored in queue

// Follows the BFS approach using the queue and setting & checking if the
// NULL value is already encountered or not, if yes then NULL value should be the last
// value in the tree, else it is not a complete binary tree