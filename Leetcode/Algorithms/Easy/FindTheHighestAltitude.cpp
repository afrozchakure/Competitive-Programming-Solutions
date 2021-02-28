class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int sum = 0;
        int result = 0;
        
        for(int i=0; i<gain.size(); i++)
        {
            sum += gain[i];
            result = max(sum, result);
        }
        
        return result;
    }
};

// Time Complexity - O(N)
// Space Complexity - O(1), constant space
