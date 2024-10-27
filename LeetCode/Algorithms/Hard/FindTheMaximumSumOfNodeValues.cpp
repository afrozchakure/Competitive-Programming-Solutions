class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        // When would XOR increase a value? 
        // What if it increases one but decreases other? 
        // One num can be XOR'd multiple times 
        // Does a traversal make sense? 

        // XOR is not a blackbox, n ^ k ^ k = n 
        // Thus we can (and must) XOR any two nodes at a time 
        // Greedy, sort by XOR delta

        long long result = 0; 
        vector<long long> delta; 
        for(long long i=0; i<nums.size(); i++) {
            result += nums[i]; 
            delta.push_back((nums[i] ^ k) - nums[i]); 
        }

        sort(delta.begin(), delta.end(), greater<>()); 
        for(long long i=0; i<delta.size(); i+= 2) {
            if(i == delta.size() - 1) {
                break; 
            }
            long long path_delta = delta[i] + delta[i + 1]; 
            if(path_delta <= 0) {
                break; 
            }
            result += path_delta; 
        }

        return result; 
    }
};

// Tree is a connected graph that doesn't have cycles in it

// n ^ k ^ k = n 

// either you leave the node as it is or XOR nodes twice

// maximize the total sum of values

// Time Complexity - O(NlogN) 
// Space Complexity - O(N), extra space 