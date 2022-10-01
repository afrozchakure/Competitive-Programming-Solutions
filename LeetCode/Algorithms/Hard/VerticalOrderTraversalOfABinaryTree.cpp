// (row + 1, col - 1) and (row + 1, col + 1)

    // (0, 0)
//     (    )
// (1, -1)  (1, 1) 
//         (      )
      // (2, 0)    (2, 2)

// Rules for sorting:
// 1. Smaller X coordinate first 
// 2. If X coordinates are same 
//     1. Greater Y coordinate 
//     2. If Y coordinate is same 
//         1. Smaller Value 

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    class Point{
        int x; 
        int y; 
        int val; 

        Point(int x, int y, in val) {
            this.x = x; 
            this.y = y; 
            this.val = val; 
        }
    }

    struct ComparePoints{ 
        bool operator() (Point const& a, Point const& b) {
            if(a.x != b.x) {
                return a.x < b.x;  
            } else {
                if(a.y != b.y) {
                    return a.y > b.y; 
                } else {
                    return a.val > b.val; 
                }
            }
        }
    }
    priority_queue<Point, vector<Point>, ComparePoints> pq; 
        
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> result; 
        treeTraversal(root, 0, 0); 

        int prevXIndex = NULL;  // It'll tell us whether to create a new array or use a previous array 
        vector<int> subArray; 
        while(!pq.empty()) {
            Point head = pq.top(); 
            pq.pop(); 
            if(prevXIndex != NULL && head.x != prevXIndex) {  // if current is different from previous pull out element 
                result.push_back(sub); 
                subArray = {}; 
            }
            subArray.add(head->val); 
        }

        if(subArray.size() > 0) {
            res.add(subArray); 
        }
        return result; 
    }

    void treeTraversal(TreeNode * root, int x, int y) {
        if(root == NULL) return; 

        Point p = new Point(root, x, y); 
        pq.push(p);
        treeTraversal(root->left, x+1, y-1); 
        treeTraversal(root->right, x+1, y+1);  
    }
};

// 1. check if whose value of x is minimum 
// 2. If x is different 
    // 1. Check whose value of y is smaller 
    // 2. If value of y is same, 
            // check which value of point is smaller 


struct Point {
    int x, int y, int val; 
}

struct ComparePoint {
    bool operator() (Point const& a, Point const&b ) {
        if(a.x != b.x) {
            return a.x < b.x; 
        } else {
            if(a.y != b.y) {
                return a.y > b.y; 
            } else {
                return a.val < b.val; 
            }
        }
    }
}