int isBSTUtil(Node* root, int minVal, int maxVal) {
        if(root == NULL) return 1; 
        // cout<<root->data<<" "<<minVal<<" "<<maxVal<<endl;
        if(root->data > minVal && root->data < maxVal && 
        isBSTUtil(root->left, minVal, root->data) && 
        isBSTUtil(root->right, root->data, maxVal)) {
            return 1; 
        }
        return 0; 
}

//Function to check whether a Binary Tree is BST or not.
bool isBST(Node* root) 
{
    // Your code here
    if(isBSTUtil(root, INT_MIN, INT_MAX)) 
        return true;
    return false;
}

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(Height of the BST).