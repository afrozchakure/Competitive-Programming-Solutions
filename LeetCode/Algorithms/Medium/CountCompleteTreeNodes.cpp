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
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0; 
        else {
            return 1 + countNodes(root->right) + countNodes(root->left); 
        }
    }
};

// Method - 2 
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0; 
        int height = 1; 

        TreeNode *left = root->left; 
        TreeNode *right = root->right; 

        while(left != NULL && right != NULL) {
            left = left->left; 
            right = right->right; 
            height++; 
        }

        return (null == left && null == right) ? pow(2, n) - 1 : 1 + countNodes(root->left) + countNodes(root->right); 
    }
};

// Given n levels of a perfect binary tree, 2^n - 1 is the number of 
// nodes of the binary search tree 

// Check the height of left-most leaf node of subtree 
// Find height of right-most leaf node of subtree

// perfectly aligned binry tree - 2^n - 1 = 2**3 - 1 = 7 

// 2**2 - 1 = 3 

// total number of nodes - 7 + 3 + 1 = 11 nodes 

// start from root, find height of rightmost and leftmost leaf node 
    // if there is a mismatch 
        // find no. of nodes in right and left subtree separately 

// for finding depth complexity is (log n)

identifying depth of right-most and left-most child - log n 
iterating towards bottom worst-case - logn 
total - log n * log n