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
    void flatten(TreeNode *root)
    {
        if (root == NULL)
            return;

        stack<TreeNode *> s;

        s.push(root);
        while (!s.empty())
        {
            TreeNode *temp = s.top();
            s.pop();
            if (temp->right != NULL)
                s.push(temp->right);
            if (temp->left != NULL)
                s.push(temp->left);

            if (!s.empty())
                temp->right = s.top();

            temp->left = NULL;
        }
    }
};

// First push the root onto the stack and push the right value first onto the stack and then the left value
// after that check if the temp is not empty, then assign the right of the "root" to "top of stack value"
// and assign the left of temp to NULL