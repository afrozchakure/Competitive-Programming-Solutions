// Method - 1 // Another Method
class Solution
{
public:
    int kthSmallest(TreeNode *root, int k)
    {
        int count = 0;
        return inorder(root, count, k);
    }
    int inorder(TreeNode *root, int count, int k)
    {
        stack<TreeNode *> s;

        TreeNode *curr = root;

        while (curr != NULL || s.empty() == false)
        {
            while (curr != NULL)
            {
                s.push(curr);
                curr = curr->left;
            }

            curr = s.top();
            s.pop();

            // cout << curr->val << " ";
            count++;
            if (count == k)
                return curr->val;
            curr = curr->right;
        }
        return 0;
    }
};

// Time Complexity - O(N)
// Space Complexity - O(N)

// Method - 2 // Preferred Method to find Inorder
class Solution
{
public:
    int kthSmallest(TreeNode *root, int k)
    {
        int count = 0;
        return inorder(root, k, count);
    }
    int inorder(TreeNode *root, int k, int count)
    {
        stack<TreeNode *> s;

        TreeNode *curr = root;
        while (1)
        {
            while (curr != NULL)
            {
                s.push(curr);
                curr = curr->left;
            }

            if (s.empty())
                break;
            else
            {
                curr = s.top();
                s.pop();
            }

            count++;

            if (count == k)
                return curr->val;

            curr = curr->right;
        }
        return 0;
    }
};

// Method - 3
class Solution
{
public:
    set<int> set;
    int kthSmallest(TreeNode *root, int k)
    {
        int count = 0;
        inorder(root, k, count);
        return *next(set.begin(), k - 1);
    }
    void inorder(TreeNode *root, int k, int count)
    {
        stack<TreeNode *> s;

        TreeNode *curr = root;
        while (1)
        {
            while (curr != NULL)
            {
                s.push(curr);
                curr = curr->left;
            }

            if (s.empty())
                break;
            else
            {
                curr = s.top();
                s.pop();
            }

            set.insert(curr->val);

            curr = curr->right;
        }
        return;
    }
};