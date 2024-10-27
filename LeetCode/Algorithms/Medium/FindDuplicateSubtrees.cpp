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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, vector<TreeNode*>> map; 
        vector<TreeNode *> dups; 

        serialize(root, map); 
        for(auto it = map.begin(); it != map.end(); it++) {
            if(it->second.size() > 1) dups.push_back(it->second[0]); 
        }

        return dups; 
    }

    string serialize(TreeNode *node, unordered_map<string, vector<TreeNode *>> &map) {
        if(!node) return ""; 
        string s = "(" + serialize(node->left, map) + to_string(node->val) + serialize(node->right, map) + ")";
        map[s].push_back(node); 
        return s; 
    }
};

// Time Complexity - O(N) 
// Space Complexity - O(N), since we're using a map