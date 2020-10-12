#include <algorithm>
#include<unordered_map>
class Solution {
public:
    
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), greater<int>());
        
        unordered_map<int, int> umap;  // using an unordered map
        int count = 0;
        for(int i=0; i<nums.size(); i++)
        {
            int elem = nums[i];
            for(int j=i+1; j<nums.size(); j++)
            {
                if(elem - nums[j] == k)
                {
                    if(umap.find(nums[i]) != umap.end())  // if the key is found in the map
                        continue;
                    else // if the element is not present in the unordered_map
                        umap.insert(make_pair(nums[i], nums[j]));
                    cout<<nums[i]<<" "<<nums[j]<<endl;
                    count += 1;
                }
            }
        }
        return count;
    }
};

// Time Complexity - O(n**2)
// Space Complexity - O(n)
