// Method 1 (Recursive)
class Solution
{
public:
    set<int> s;
    int findSecondMinimumValue(TreeNode *root)
    {
        dfs(root);
        if (s.size() < 2)
            return -1;
        return *next(s.begin(), 1);
    }
    void dfs(TreeNode *root)
    {
        if (root == NULL)
            return;
        s.insert(root->val);
        dfs(root->left);
        dfs(root->right);
    }
};

// Time Complexity - O(N)
// Space Complexity - O(N)

// Method - 2 (Iterative)
#include <stack>
#include <set>
class Solution
{
public:
    set<int> s;
    int findSecondMinimumValue(TreeNode *root)
    {
        dfs(root);
        if (s.size() < 2)
            return -1;
        return *next(s.begin(), 1);
    }

    void dfs(TreeNode *root)
    {
        stack<TreeNode *> stack;
        TreeNode *curr = root;
        while (1)
        {
            while (curr != NULL)
            {
                stack.push(curr);
                curr = curr->left;
            }

            if (stack.empty())
                return;
            else
            {
                curr = stack.top();
                // cout << curr->val << " ";
                stack.pop();
            }

            s.insert(curr->val);

            curr = curr->right;
        }
        return;
    }
};

// Time Complexity - O(N)
// Space Complexity - O(N), since we used set