long long treePathsSumUtil(Node *root, int val)
{
    if(root == NULL) 
        return 0; 
    
    // update val 
    val = (val * 10 + root->data);
    
    if(root->left == NULL && root->right == NULL)
        return val; 
        
    return treePathsSumUtil(root->left, val) + treePathsSumUtil(root->right, val);
}

/*You are required to complete below method */
long long treePathsSum(Node *root)
{
    //Your code here
    return treePathsSumUtil(root, 0);   
}

// Time Complexity - O(N), N is number of nodes in tree 
// Space Complexity - O(N), implicit stack space
