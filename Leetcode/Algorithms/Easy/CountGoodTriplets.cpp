class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int count = 0;
        for(int i=0; i<arr.size() - 2; i++)
        {
            for(int j=i+1; j<arr.size() - 1; j++)
            {
                for(int k=j+1; k<arr.size(); k++)
                {
                    if(i < j && j < k && abs(arr[i] - arr[j]) <= a && abs(arr[j] - arr[k]) <= b && abs(arr[i] - arr[k]) <= c)
                    {   
                        count++;
                    }
                    
                }
            }
        }
        return count;
    }
                       
};

// Time Complexity - O(n**3)
// Space Complexity - O(1)
