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
    TreeNode *constructFromPrePost(vector<int> &pre, vector<int> &post)
    {
        int n = pre.size();
        int preStart = 0;
        int postStart = 0;
        int preEnd = n - 1;
        int postEnd = n - 1;
        helper(pre, post, preStart, preEnd, postStart, postEnd);
    }

    // preorder - D L R
    // postorder - L R D
    TreeNode *helper(vector<int> &pre, vector<int> &post, int preStart, int preEnd, int postStart, int postEnd)
    {
        TreeNode *root = new TreeNode(pre[preStart]);

        if (preStart == preEnd)
            return root;

        // Setting the left root
        int leftStart = pre[preStart + 1];

        int postIndex;
        for (int i = 0; i < preEnd; i++)
        {
            if (post[i] == pre[leftStart])
                postIndex = i;
        }
        // preorder - D L R
        // postorder - L R D

        root->left = helper(pre, post, preStart + 1, preEnd, postIndex + 1, postEnd + postIndex - 1);
        root->right = helper(pre, post, preEnd, preEnd, postIndex + 1, postEnd - 1);

        return root;
    }
};