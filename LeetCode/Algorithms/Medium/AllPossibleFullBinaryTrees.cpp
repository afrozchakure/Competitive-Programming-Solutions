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
    vector<vector<TreeNode*>> dp; 
    vector<TreeNode*> allPossibleFBT(int n) {

        return solve(n); 
    }

    vector<TreeNode *> solve(int n) {
        if(n == 0) {
            return vector<TreeNode *>{}; 
        }

        if(n == 1) {
            return new TreeNode(0); 
        }

        if(dp.find(n)) {
            return dp[n]; 
        }

        vector<TreeNode *> result; 

        for(int l = 0; l<n; l++) {
            r = n - 1 - l; 
            vector<TreeNode *> leftTrees = solve(l); 
            vector<TreeNode *> rightTrees = solve(r); 

            for(auto &t1: leftTrees) {
                for(auto &t2: rightTrees) {
                    result.push_back(TreeNode(0, t1, t2)); 
                }
            }
        }
        dp[n] = result; 
        return result; 
    }
};