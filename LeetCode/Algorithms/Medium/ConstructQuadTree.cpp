/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node *zero = new Node(false, true); 
    Node *one = new Node(true, true); 

    Node* construct(vector<vector<int>>& grid) {
        return dfs(grid, grid.size(), 0, 0); 
    }

    Node* dfs(vector<vector<int>>& grid, int n, int row, int col) {
        if(n == 1) {
            return grid[row][col] == 1 ? one : zero; 
        }

        n = n / 2;

        Node *topLeft = dfs(grid, n, row, col); 
        Node *topRight = dfs(grid, n, row, col + n); 
        Node *bottomLeft = dfs(grid, n, row + n, col); 
        Node *bottomRight = dfs(grid, n, row+n, col+n); 

        if(topLeft == topRight && topRight == bottomLeft && bottomLeft == bottomRight && bottomRight == topLeft) {
            return topLeft; 
        }
        return new Node(0, false, topLeft, topRight, bottomLeft, bottomRight); 
    }
};