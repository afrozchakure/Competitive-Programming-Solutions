// Basic idea is to traverse each level and during that time each of the elements
// is in the queue, since we pushed the right elements first into the queue
// We will push that elements onto the vector first

// BFS Solution
class Solution
{
public:
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> result;
        queue<TreeNode *> q;
        if (root == NULL)
            return {};
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            // It is important to calculate queue size globally first
            // and not within the for loop
            for (int i = 0; i < size; i++)
            {
                TreeNode *temp = q.front();
                q.pop();
                if (i == 0)
                    result.push_back(temp->val);
                if (temp->right != NULL)
                    q.push(temp->right);
                if (temp->left != NULL)
                    q.push(temp->left);
            }
        }
        return result;
    }
};

// Time Complexity - O(n)
// Space Complexity - O(n)  --> Used queue for storage