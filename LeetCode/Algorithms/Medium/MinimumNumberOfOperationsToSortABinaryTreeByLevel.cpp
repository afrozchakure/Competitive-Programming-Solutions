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
    int findMinSwaps(vector<int> &values) {
        int min_swaps = 0;

        // store K->values ... V->Actual_idx ordered map
        map<int, int> sorted_map; 
        for(int i=0; i<values.size(); i++) {
            sorted_map[values[i]] = i; 
        }

        // sort the array to know the expected index
        sort(values.begin(), values.end()); 
        int iteration = 0; // row number of map 
        vector<bool> visited(values.size(), false); // this marks already processed indices

        for(auto &[val, idx]: sorted_map) {
            if(visited[idx]) {  // don't process if already done 
                iteration++; 
                continue; 
            }

            visited[idx] = true; 
            int len = 1; // find length of cycle 
            while(idx != iteration) {
                idx = sorted_map[values[idx]];
                visited[idx] = true; 
                len++; 
            }
            min_swaps += len-1;  // add no. of swaps for the current
            iteration++; 
        }
        return min_swaps; 
    }

    int minimumOperations(TreeNode* root) {
        queue<TreeNode *> q; 
        q.push(root); 

        int min_swaps = 0; 
        while(!q.empty()) {
            int size = q.size(); 
            vector<int> values; 
            for(int i=0; i<size; i++) {
                TreeNode *node = q.front(); 
                q.pop();

                values.push_back(node->val); 
                
                if(node->left) {
                    q.push(node->left); 
                }

                if(node->right) {
                    q.push(node->right); 
                }
            }
            min_swaps += findMinSwaps(values); 
        }
        return min_swaps;
    }
};

// Time Complexity - O(N + NlogN + NlogN) ~ O(NlogN), sorting and map
// traversig n nodes
// NlogN since we're using a sorted map
// NlogN since we're using a sorted array 
// Space Complexity - O(N), since we're using a map

// Example: node values are [7, 11, 3, 5, 2].
// The index array, after sorting, will look like this: [3, 4, 1, 2, 0].

// Optimal, tree, sorting, BFS

// Note: Unsorted array always exists as cycle
// a[] = [3 1 2]
//        0 1 2 

// WE need 1- rotation of cycle to sort 
// cycle size = 2 = (n - 1), n is the unsorted cycle size
// in 1 step only 1 element gets placed in correct position
// in last step 2 elements get placed in their correct position

// Cycle size = 3, no. of swaps = 2

// Swaps to Sort = Cycle length - 1

// skip swap when:
// 1. iteration == idx
// 2. visited == true

// step 1- build a sorted map 
// step 2: sort values to get index of elements in a sorted array 
// step 3: iterate over each item in sorte dmap and find cycle length starting 
// at given idx

// 