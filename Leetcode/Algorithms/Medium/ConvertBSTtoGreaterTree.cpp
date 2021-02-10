// Recursive Solution
class Solution
{
public:
    int sum = 0;
    TreeNode *convertBST(TreeNode *root)
    {
        if (root != NULL)
        {
            convertBST(root->right);
            sum += root->val;
            root->val = sum;
            convertBST(root->left);
        }
        return root;
    }
};

// Time Complexity - O(N)
// Space Complexity - O(N)

// Iterative Solution
class Solution
{
public:
    TreeNode *convertBST(TreeNode *root)
    {

        stack<TreeNode *> s;
        TreeNode *curr = root;
        int sum = 0;

        while (curr != NULL || s.empty() == false)
        {
            while (curr != NULL)
            {
                s.push(curr);
                curr = curr->right;
            }
            // pop the element
            curr = s.top();
            s.pop();

            // Increment the node with sum of right subtree
            sum += curr->val;
            curr->val = sum;

            // iterate left subtree
            curr = curr->left;
        }
        return root;
    }
};

// Time Complexiy - O(N)
// Space Complexity - O(N)