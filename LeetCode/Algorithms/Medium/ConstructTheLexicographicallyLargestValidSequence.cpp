class Solution {
public:
    bool findLargestArray(vector<int> &result, vector<bool> &used, int pos, int n) {
        if(pos == 2 * n - 1) {
            return true; 
        }

        if(result[pos] != 0) {  // already filled
            return f(result, used, pos + 1, n); 
        }

        // Try assigning all unused values 
        for(int i=n; i>=1; i--) {
            if(used[i] == true) continue; 

            used[i] = true; 
            result[pos] = i; 
            if(i == 1 && findLargestArray(result, used, pos + 1, n)) {
                return true; 
            } 
            if(i > 1 && (pos + i) < (2 * n - 1) && result[pos + i] == 0) {
                result[pos + i] = i; 
                if(findLargestArray(result, used, pos + 1, n)) {
                    return true; 
                }

                result[pos + i] = 0; 
            }
            used[i] = false; 
            result[pos] = 0; 
        }
        return false; 
    }
    
    vector<int> constructDistancedSequence(int n) {
        vector<bool> used(n + 1, false); 
        vector<int> result(2 * n - 1, 0); 

        findLargestArray(used, result, 0, n); 
        return result; 
    }
};


// Time Complexity - O(N!)
// Space Complexity - O(N), depth of recursion 

// Runtime << N! because: 
// 1. Equi-distant placement of Nos reduces a lot of arrangements of N!
// 2. Early stopping by greedy recursion

