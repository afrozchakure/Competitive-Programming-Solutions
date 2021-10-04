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
 
// DFS (with stack)
class Solution
{
public:
    bool hasPathSum(TreeNode *root, int sum)
    {
        if (root == NULL)
            return false;
        stack<TreeNode *> node_stack;
        stack<int> sum_stack;

        node_stack.push(root);
        sum_stack.push(sum - root->val);

        while (!node_stack.empty())
        {
            TreeNode *current_node = node_stack.top();
            node_stack.pop();
            int current_sum = sum_stack.top();
            sum_stack.pop();

            // Means that we have reached the leaf nodes and the current_sum = 0
            if (current_node->left == NULL && current_node->right == NULL && current_sum == 0)
                return true;

            if (current_node->left != NULL)
            {
                node_stack.push(current_node->left);
                sum_stack.push(current_sum - current_node->left->val);
            }
            if (current_node->right != NULL)
            {
                node_stack.push(current_node->right);
                sum_stack.push(current_sum - current_node->right->val);
            }
        }
        return false;
    }
};

// Time Complexity - O(N)
// Space Complexity - O(N), since we're using a stack to store current values
