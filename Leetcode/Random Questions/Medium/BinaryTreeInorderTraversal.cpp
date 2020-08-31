// Using Stack and Vector

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
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector <int> final_vec;
        stack <TreeNode* > curr_stack;
        TreeNode* p = root;
        while(p != NULL || !curr_stack.empty())
        {
            if(p)
            {
                curr_stack.push(p);
                p = p->left;
            }
            else{
                p = curr_stack.top();
                curr_stack.pop();
                final_vec.push_back(p->val);
                p = p->right;
            }
        }
        return final_vec;
    }
};

// Time Complexity - O(n)
// Space Complexity - O(3n)

// Using Recursion 
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
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> nodes;
        inorder(root, nodes);
        return nodes;
    }
    void inorder(TreeNode* root, vector<int>& nodes)
    {
        if(root == NULL)  return;
        inorder(root->left, nodes);
        nodes.push_back(root->val);
        inorder(root->right, nodes);
    }
};

// Time Complexity - O(n)
// Space Complexity - O(n)
