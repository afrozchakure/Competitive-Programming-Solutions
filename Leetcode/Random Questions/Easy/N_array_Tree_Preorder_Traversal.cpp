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

class Solution
{
public:
    vector<int> preorder(Node *root)
    {
        stack<Node *> s;
        vector<int> output;

        if (root == NULL)
            return output;

        s.push(root);
        while (!s.empty())
        {
            Node *temp = s.top();
            s.pop();
            for (int i = temp->children.size() - 1; i >= 0; i--)
                s.push(temp->children[i]);
            output.push_back(temp->val);
        }
        return output;
    }
};

// Time Complexity - O(n) - n is the no. of nodes in the tree
// Space Complexity - O(n) - Used stack and vector