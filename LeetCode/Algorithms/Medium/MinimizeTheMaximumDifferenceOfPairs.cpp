class Solution {
public:
    bool isValid(int threshold, int p) {
        int i = 0, count = 0; 

        while(i < nums.size() - 1) {
            if(abs(nums[i] - nums[i + 1]) <= threshold) {
                count++; 
                i += 2;
            } else {
                i += 1; 
            }

            if(count == p) {
                return true; 
            }
        }
        return false;
    }
    int minimizeMax(vector<int>& nums, int p) {
        int n = nums.size(); 
        sort(nums.begin(), nums.end()); 
        
        
        int l = 0, r = 10e9; 

        int res = 10e9; 
        
        while(l <= r) {
            int mid = l + (r - l) / 2; 

            if(isValid(mid, p)) {
                res = mid; 
                r = mid - 1; 
            } else {
                l = mid + 1; 
            }
        }
        return res; 
    }
};