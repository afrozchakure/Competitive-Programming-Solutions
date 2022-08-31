// - Time Complexity - O(N)
// - Space Complexity - O(N)
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL) return {};
        queue<TreeNode *> q; 
        q.push(root); 
        vector<vector<int>> result; 
        while(!q.empty()) {
            int n = q.size(); 
            vector<int> sub; 
            for(int i=0; i<n; i++) {
                TreeNode *temp = q.front(); 
                q.pop(); 
                sub.push_back(temp->val); 
                if(temp->left) {
                    q.push(temp->left); 
                } 
                if(temp->right) {
                    q.push(temp->right); 
                }
            }
            result.push_back(sub);
        }      
        return result;
    }
};