// Using Depth First Search

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
    int ans;
    int distributeCoins(TreeNode *root)
    {
        ans = 0;
        give_coins(root);
        return ans;
    }
    int give_coins(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        int L = give_coins(root->left);
        int R = give_coins(root->right);

        // This will be the absolute values of Left and right
        ans += abs(L) + abs(R);

        // It is used to get root->val - 1 value from the root node
        return root->val - 1 + L + R;
    }
};

// Follows Postorder Approach and return the balance of coins.
// Read the diagramatic solution from here
// https://leetcode.com/problems/distribute-coins-in-binary-tree/discuss/221939/C%2B%2B-with-picture-post-order-traversal