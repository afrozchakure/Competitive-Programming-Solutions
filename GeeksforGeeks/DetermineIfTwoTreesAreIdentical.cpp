// Recursive solution 
bool isIdentical(Node *r1, Node *r2)
{
    //Your Code here
    
    if(r1 == NULL && r2 == NULL)
    {
        return true;
    }
    
    if(r1 == NULL || r2 == NULL)
    {
        return false;
    }
    
    if(r1->data == r2->data)
    {
        isIdentical(r1->left, r2->left); 
        isIdentical(r1->right, r2->right);
    }
    else 
    {
        return false; 
    }
}

// Time Complexity - O(min(X1, X2)), X1 and X2 are the number of nodes in respective tree 
// Space Complexity - O(N), implicit stack       
    

