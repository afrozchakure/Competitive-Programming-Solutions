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

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> result;
        
        queue<Node *> q;
        
        if(root == NULL)
            return result;
        q.push(root);
        while(!q.empty())
        {
            int size = q.size();
            
            vector<int> subarray;
            for(int i= 0; i<size; i++)
            {
                Node *temp = q.front();
                q.pop();
                
                subarray.push_back(temp->val);
                for(Node *child: temp->children)
                {
                    q.push(child);
                }
            }
            result.push_back(subarray);
        }
        return result;
    }
};

// Time Complexity - O(V), V is the number of nodes present in the tre
// Space Complexity - O(V), since we're using a queue of size V
