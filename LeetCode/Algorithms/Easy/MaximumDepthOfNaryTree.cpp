/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

// DFS recursive stack solution
class Solution {
public:
    int maxDepth(Node* root) {
        if(root == NULL)   
            return 0;
        
        int depth = 0;
        for(auto child: root->children) depth = max(depth, maxDepth(child));
        
        return depth + 1; 
    }
};

// Time Complexity - O(N), n is the no. of nodes in the tree 
// Space Complexit - O(N), maximum elements in a stack at a tim

// BFS (Breadth first search) 

class Solution{
    int maxDepth(Node* root) {
        if(root == NULL)
            return 0;

        queue<Node*> q;
        int depth = 0;
        q.push(root);
        while(!q.empty())
        {
            depth += 1;

            int size = q.size();

            for(int i=0; i<size; i++)
            {
                Node *temp = q.front();
                q.pop();

                for(auto child: temp->children)
                {
                    if(child)
                        q.push(child);
                }
            }
        }
        return depth;
    }
};

// Time Complexity - O(N)
// Space Complexity - O(N), since we're using a queue
