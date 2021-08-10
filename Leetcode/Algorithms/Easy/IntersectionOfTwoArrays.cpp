class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s(nums1.begin(), nums1.end());
        
        vector<int> result;  // intersection
        
        for(auto ele: nums2)
        {
            if(s.count(ele) > 0)
            {
                result.push_back(ele);
                s.erase(ele);
            }
        }
        return result;
    }
};


// Time Complexity - O(N)
// Space Complexity - O(N), since we're using an unordered_set and a vector

// first add nums1 to unordered set and then compare from nums2 which elements are there in unordered_set and add then to result vector
