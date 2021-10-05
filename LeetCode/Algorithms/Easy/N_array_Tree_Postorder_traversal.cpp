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
    vector<int> postorder(Node *root)
    {
        stack<Node *> s;
        vector<Node *> output;
        if (root == NULL)
            return output;
        s.push(root);

        while (!s.empty())
        {
            Node *temp = s.top();
            s.pop();
            for (int i = 0; i < temp->children.size(); i++)
                s.push(temp->children[i]);
            output.push_back(temp);
        }

        reverse(output.begin(), output.end());
        return output;
    }
};