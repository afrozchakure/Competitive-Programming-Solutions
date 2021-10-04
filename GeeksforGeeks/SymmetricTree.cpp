bool isMirror(Node *root1, Node *root2)
    {
        if(root1 == NULL && root2 == NULL)
            return true;
        
        if(root1 && root2 && root1->data == root2->data)
        {
            return isMirror(root1->left, root2->right) && isMirror(root1->right, root2->left);
        }
        return false;
    }

    // return true/false denoting whether the tree is Symmetric or not
bool isSymmetric(struct Node* root)
{
    return isMirror(root, root);
}

// Time Complexity - O(N), N is the number of nodes in the tree
// Space Complexity - O(N), implicit stack
