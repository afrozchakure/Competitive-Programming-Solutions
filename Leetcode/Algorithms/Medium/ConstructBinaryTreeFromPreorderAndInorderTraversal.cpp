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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        return helper(0, 0, inorder.size() - 1, preorder, inorder);
    }

    // preorder - D L R
    // Inorder - L D R

    TreeNode *helper(int preStart, int inStart, int inEnd, vector<int> &preorder, vector<int> &inorder)
    {
        if (preStart > preorder.size() - 1 || inStart > inEnd)
            return NULL;

        TreeNode *result = new TreeNode(preorder[preStart]);

        int inIndex = 0;

        for (int i = inStart; i <= inEnd; i++)
        {
            if (result->val == inorder[i])
                inIndex = i;
        }

        result->left = helper(preStart + 1, inStart, inIndex - 1, preorder, inorder);
        result->right = helper(preStart + inIndex - inStart + 1, inIndex + 1, inEnd, preorder, inorder);

        return result;
    }
};

// Watch Jenny's Videos on the topic and Nick White's video tutorial