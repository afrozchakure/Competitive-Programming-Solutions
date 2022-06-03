// - Time Complexity - O(N) 
// - Space Complexity - O(N), where N is the number of nodes in the binary tree 

class Solution {
public:
    int ans = 0; 
    pair<int, int> solve(TreeNode *root) {
        if(root == NULL) return {0, 0}; 
        
        auto left_pair = solve(root->left); 
        int left_count = left_pair.second; 
        int left_sum = left_pair.first; 
        
        auto right_pair = solve(root->right); 
        int right_count = right_pair.second; 
        int right_sum = right_pair.first; 
        
        int sum = root->val + left_sum + right_sum; 
        int count = left_count + right_count + 1; 
        
        if((sum / count) == root->val) {
            ans++; 
        }   
        return {sum, count}; 
    }
    
    int averageOfSubtree(TreeNode* root) {
        solve(root);  // Here we don't necessarily require to store the returned value of root
        return ans; 
    } 
};
