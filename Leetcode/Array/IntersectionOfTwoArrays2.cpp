class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> s;
        for(int i=0; i<nums1.size(); i++)
            s[nums1[i]]++;
        vector<int> result;
        for(int i=0; i<nums2.size(); i++)
            if(s.find(nums2[i]) != s.end()){
                s[nums2[i]]--;
                if(s[nums2[i]] == 0) s.erase(nums2[i]);
                result.push_back(nums2[i]);
            }
        return result;           
    }
};

// Time Complexity : O(m+n)
// Space Complexity: O(m)

