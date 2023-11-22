class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> list; 

        dfs(n, k, list, 0); 
        return list;       
    }

    void dfs(int n, int k, vector<int> &list, int currNo) {
        if(n <= 0) {
            list.push_back(currNo); 
            return; 
        }

        for(int i=0; i<10; i++) {
            if(i == 0 && currNo == 0) { // skip the case with leading 0
                continue; 
            } else if(i != 0 && currNo == 0) { // base case when currNo is 0
                dfs(n - 1, k, list, i); 
            } else if(abs(currNo % 10 - i) == k) {  // adding i at the units place of the currNo (Valid case where the difference between the previous digit and i is K)
                dfs(n-1, k, list, currNo *10 + i);
            }
        }
    }
};

// Time Complexity - O(N * 2^N)
// Space Complexity - O(2^N)