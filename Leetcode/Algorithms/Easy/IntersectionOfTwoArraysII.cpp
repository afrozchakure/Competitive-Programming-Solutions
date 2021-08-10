class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> s;
        for(int x: nums1)
            s[x]++;
        vector<int> result;
        for(int y: nums2)
            if(s.find(y) != s.end())
            {
                s[y]--;
                if(s[y] == 0) s.erase(y);
                result.push_back(y);
            }
        return result;
    }
};

// Time Complexity - O(N)
// Space Complexity - O(N), since we're using unordered_map and vector to store the result
