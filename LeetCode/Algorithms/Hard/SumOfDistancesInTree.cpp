class Solution {
public:
    vector<int> result; 
    vector<int> count; 
    unordered_map<int, vector<int>> tree; 
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        result = vector<int>(n); 
        count = vector<int>(n); 

        for(auto &e: edges) {
            tree[e[0]].push_back(e[1]); 
            tree[e[1]].push_back(e[0]); 
        }
        postOrder(0, -1); 
        preOrder(0, -1); 
        return result; 
    }

    void postOrder(int root, int pre) {
        for(int i : tree[root]) {
            if(i == pre) continue; 
            postOrder(i, root); 
            count[root] += count[i]; 
            result[root] += result[i] + count[i]; 
        }
        count[root]++;  
    }

    void preOrder(int root, int pre) {
        for(int i: tree[root]) {
            if(i == pre) continue; 
            result[i] = result[root] - count[i] + count.size() - count[i]; 
            preOrder(i, root); 
        }
    }
};


// We are calculating the depth of each node from original node 

// Dis[i] = Dis[root] - count[i] +             (count.length       -    count[i]);
            // depth   (count of closer nodes) (count of farther nodes)

// how many nodes fall under each subtree + 1 
// We are calculating the nodes within each subtree 

Calculate depth 