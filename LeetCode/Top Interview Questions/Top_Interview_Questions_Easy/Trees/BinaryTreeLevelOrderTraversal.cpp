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
    vector<vector<int>> ret;
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        
        // Defining Queue
        queue <TreeNode *> Q;
        // Defining Vector
        vector<int> temp;
        
        Q.push(root);
        while(!Q.empty()){
            int q_size = Q.size();  // Getting the size from the queue  
            for(int i=0; i<q_size; i++)
            {
                TreeNode* curr = Q.front();
                temp.push_back(curr->val);
                Q.pop();        
                if(curr->left != NULL) Q.push(curr->left);  
                if(curr->right != NULL) Q.push(curr->right);
            }
             ret.push_back(temp);
             temp.clear();  
        }
        return ret;
        }
};
