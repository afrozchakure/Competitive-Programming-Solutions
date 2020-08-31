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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0) 
            return NULL;
        return solution(nums, 0, nums.size()-1);
    }
    TreeNode* solution(vector<int>& nums, int i, int j)
    {
        TreeNode *root = new TreeNode;
        int mid = (i+j) / 2;
        root->val = nums[mid];
        if(i == j)
            return root;
        if((mid-1) >= i)
            root->left = solution(nums, i, mid-1);
        if((mid+1) <= j)
            root->right = solution(nums, mid+1, j);
        return root;
    }
};

// Time Complexity - O(n)
// Space Complexity - O(n)
