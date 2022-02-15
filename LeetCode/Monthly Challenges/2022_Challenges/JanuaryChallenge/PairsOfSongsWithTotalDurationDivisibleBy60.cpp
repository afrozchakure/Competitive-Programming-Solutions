class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int count = 0;
        map<int, int> mp; 
        
        for(int &t: time)
        {
            count += mp[(60 - t%60) % 60]; 
            mp[t % 60] += 1; 
        }
        return count;
    }
};

// Time Complexity - O(n) 
// Space Complexity - O(60) // constant time complexity 
// It gets converted into a two-sum problem once we work with the modulo part --> refer notebook for details or lee's solution
