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
    vector <vector<int>> ret;
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL) return {};
        
        vector<vector<int>> result;
        
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            vector<int> subarr;
            int q_size = q.size();
            for(int i=0; i<q_size; i++)
            {
                TreeNode *temp = q.front();
                subarr.push_back(temp->val);
                q.pop();
                if(temp->left != NULL) 
                {
                    q.push(temp->left);
                }
                if(temp->right != NULL) 
                {
                    q.push(temp->right);
                }
            }
            
            result.push_back(subarr);
        }
        return result;
        
    }
};
