class Solution {
public:
    int numTrees(int n) {
        // numTree[4] = numTree[0] * numTree[3] + 
        //              numTree[1] * numTree[2] +       
        //              numTree[2] * numTree[1] + 
        //              numTree[3] * numTree[0]

        vector<int> numTree(n + 1, 1); 

        // 0 nodes = 1 tree 
        // 1 nodes = 1 tree 
        for(int nodes=2; nodes<n+1; nodes++) {  // find total number of elements 
            int total = 0; 
            for(int root=1; root<nodes+1; root++) {
                left = root - 1;    // 3 -1 = 2 
                right = nodes - root;   // total nodes - root_node - 4 - 2 = 2 
                total += numTree[left] * numTree[right]; 
            }
            numTree[nodes] = total; 
        }
        return numTree[n]; 
    }
};

// numTree[0] = 1; 
// numTree[1] = 1; 

// nodes - 2
// root  - 1

// nodes - 3 
// root  - 1, 2
    // when root = 1 
        // left = 0 
        // right = 3 - 1 = 2 
    
    // when root = 2 
        // left = 1 
        // right = 3 - 2 = 1 

// nodes - 4 
// root - 1, 2, 3 
    // when root = 1
        // left = 0 
        // right = 4 - 1 = 3 

    // when root = 2 
        // left = 1 
        // right = 4 - 2 = 2 

    // when root = 3
        // left = 2 
        // right = 4 - 3 = 1 



