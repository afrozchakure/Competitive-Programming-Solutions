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
    int widthOfBinaryTree(TreeNode *root)
    {
        vector<unsigned long long> lefts; // stores the left-most nodes
        int depth = 0;
        unsigned long long id = 1;
        unsigned long long width_max = 0;
        dfs(root, id, width_max, depth, lefts);
        return width_max;
    }
    void dfs(TreeNode *node, unsigned long long id, unsigned long long &width_max, int depth, vector<unsigned long long> &lefts)
    {
        if (node == NULL)
            return;
        if (depth >= lefts.size())
            lefts.push_back(id);

        width_max = max(width_max, id - lefts[depth] + 1);
        dfs(node->left, id * 2, width_max, depth + 1, lefts);
        dfs(node->right, id * 2 + 1, width_max, depth + 1, lefts);
    }
};