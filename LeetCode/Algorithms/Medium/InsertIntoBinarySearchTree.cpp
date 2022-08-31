// Find where (leaf position) it can be & insert it 
// leaf position meaning it'll be null 
// O(logn) assuming it is a height balanced tree 

class Solution
{
public:
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {

        if (root == NULL)
            return new TreeNode(val);

        if (root->val > val)
        {
            root->left = insertIntoBST(root->left, val);
        }
        if (root->val >= val)
        {
            root->right = insertIntoBST(root->right, val);
        }
        return root;
    }
};

// Time Complexity - O(logn) or O(h) where h is the height of the tree
// Space Complexity - O(1), no extra space is required