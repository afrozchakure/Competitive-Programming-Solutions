vector <int> preorder(Node* root)
{
    vector<int> result;
  // Your code here
  if(root == NULL)    
        return result; 
    
    stack<Node *> s; 
    s.push(root); 
    // int arr_length = 0;
    while(!s.empty())
    {
        Node *temp = s.top(); 
        
        s.pop(); 
        
        result.push_back(temp->data); 
        
        if(temp->right)
        {
            s.push(temp->right);
        }
        if(temp->left)
        {
            s.push(temp->left);
        }
    }
    return result;
}

// Time Complexity - O(N)
// Space Complexity - O(N), since you're using a stack
