#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  	
  	void preOrder(Node *root) {
		
      	if( root == NULL )
          	return;
      
      	std::cout << root->data << " ";
      	
      	preOrder(root->left);
      	preOrder(root->right);
    }

/*
Node is defined as 

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

*/

    Node * insert(Node * root, int data) {
        Node *temp = new Node(data);  // Creating an object of Parametrized constructor Node(int)
        if(root == NULL)
        {
            return temp;  // Adds temp node if binary tree is empty
        }
        Node *iterator = root;
        while(iterator != NULL)
        {
        if(data < iterator->data)
        {
            if(iterator->left == NULL)
            {
                iterator->left = temp;
                break;
            }
            iterator = iterator->left;
        }
        if(data >iterator->data)
        {
            if(iterator->right == NULL)
            {
                iterator->right = temp;
                break;
            
            }
            iterator = iterator->right;
        }
        }

        return root;
    }

};

int main() {
  
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  	
    myTree.preOrder(root);
  
    return 0;
}
