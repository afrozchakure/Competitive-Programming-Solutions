class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int max1 = INT_MIN; 
        int max2 = INT_MIN;
        int min1 = INT_MAX; 
        int min2 = INT_MAX;
        for(int &element: nums)   
        {
            if(element > max1)
            {
                max2 = max1;
                max1 = element;
            }
            else if(element > max2)
            {
                max2 = element;
            }
            
            if(element < min1)
            {
                min2 = min1;
                min1 = element;
            }
            else if(element < min2)
            {
                min2 = element;
            }
        }
        return (max1 * max2) - (min1 * min2);
    }
};

// Time Complexity - O(N)
// Space Complexity - O(1)
