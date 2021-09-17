// C code (recursive)
void mirror(struct Node* node) {
    // code here
    if(node == NULL)
        return; 
    else 
    {
        struct Node *temp = (struct Node*)malloc(sizeof(struct Node*));
        mirror(node->left); 
        mirror(node->right); 
        
        temp = node->left; 
        node->left = node->right; 
        node->right = temp; 
        
        
    }
    
}
// Time Complexity - O(N) 
// Space Complexity - O(N)

// Iterative (c++) code 
void mirror(Node* node) {
        // code here
        if(node == NULL)
            return; 
            
        queue<Node *> q; 
        
        q.push(node); 
        
        while(!q.empty())
        {
            Node *curr = q.front(); 
            q.pop(); 
            
            Node *temp = curr->left; 
            curr->left = curr->right; 
            curr->right = temp; 
            
            if(curr->left)
                q.push(curr->left);
            if(curr->right)
                q.push(curr->right); 
        }
    }
    
// Time complexity - O(N) 
// Space complexity - O(1)

