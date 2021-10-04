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
    bool isSymmetric(TreeNode* root) {
       return isMirror(root, root);
        }
    bool isMirror(TreeNode *t1, TreeNode *t2)
    {
        if(t1 == NULL && t2 == NULL) return true;
        if(t1 == NULL || t2 == NULL) return false;
        
        return (t1->val == t2->val && isMirror(t1->left, t2->right) && isMirror(t1->right, t2->left));
    }
};

// Time Complexity - O(N), n is the number of nodes in the tree
// Space Complexity - O(N), implicit stack size equal to number of nodes in the tree

// BFS (Breadth First Search)

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode *> q;
        
        q.push(root);
        q.push(root);
        
        while(!q.empty())
        {
            TreeNode *t1 = q.front();
            q.pop();
            TreeNode *t2 = q.front();
            q.pop();
            
            // First check for NULL values, then check if values are equal
            if(t1 == NULL && t2 == NULL) continue;
            if(t1 == NULL || t2 == NULL) return false;
            if(t1->val != t2->val) return false;
            
            
            
            q.push(t1->right);
            q.push(t2->left);
            q.push(t1->left);
            q.push(t2->right);
        }
        return true;
    }
};

// Time Complexity - O(N)
// Space Complexity - O(N), since we're using queue
