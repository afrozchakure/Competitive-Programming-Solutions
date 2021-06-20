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
        stack<TreeNode *> s;
        vector<int> result;
        
        if(root == NULL) return result;
        
        TreeNode* current = root;
        
	// check if either the root value is null or the stack is empty
        while(current != NULL || !s.empty())
        {
	    // scan through the left side first 
            if(current != NULL)
            {
                s.push(current);
                current = current->left;
            }
            current = s.top();
            s.pop();
	    // push the current element onto the stack 
            result.push_back(current->val);
	    // set current to right side element 
            current = current->right;
        }
        return result;
    }
};

// Time Complexity - O(N)
// Space Complexity - O(N), N is the no. of nodes in the binary tree
