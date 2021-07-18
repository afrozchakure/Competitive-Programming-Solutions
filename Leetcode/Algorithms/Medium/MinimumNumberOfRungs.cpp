class Solution {
public:
    int addRungs(vector<int>& rungs, int dist) {
        int previous = 0;
        int result = 0;
        for(int &rung: rungs)
        {
            result += (rung - previous - 1) / dist;
            previous = rung;
        }
        return result;
    }
};

// Time Complexity - O(N), N is the number of elements in rungs
// Space Complexity - O(1)
