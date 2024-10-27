class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        vector<int> level_sum; 
        queue<TreeNode *> q; 

        while(!q.empty()) {
            int current_sum = 0; 

            for(int i=0; i<q.size(); i++) {
                TreeNode *node = q.front(); 
                q.pop(); 

                current_sum += node->val; 

                if(node->left) {
                    q.push(node->left); 
                }
                if(node->right) {
                    q.push(node->right); 
                }
            }

            level_sum.push_back(current_sum); 
        }      

        queue<TreeNode *> qnode; 

        qnode.push(root); 
        root->val = 0; 
        while(!qnode.empty()) {
            for(int i=0; i<qnode.size(); i++) {
                TreeNode *temp = qnode.front(); 
                qnode.pop(); 
                
                int child_sum = 0; 
                if(temp->left) {
                    child_sum += temp->left->val; 
                }

                if(temp->right) {
                    child_sum += temp->right->val; 
                }
                if(temp->left) {
                    temp->left->val = level_sum[level + 1] - current_sum; 
                    qnode.push(temp->left); 
                }   
                if(temp->right) {
                    temp->right = level_sum[level + 1] - current_sum; 
                    qnode.push(temp->right); 
                }
            }
            level++; 
        }

        return root; 
    }

};