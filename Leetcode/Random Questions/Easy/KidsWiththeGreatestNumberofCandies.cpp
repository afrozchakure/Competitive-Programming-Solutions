// Method - 1
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int max = 0;
        vector <bool> result;
        for(int i=0; i<candies.size(); i++)   
            if(candies[i] > max)
                max = candies[i];
        for(int i=0; i<candies.size(); i++)
        {
            if((candies[i] + extraCandies) >= max)
                result.push_back(true);
            else result.push_back(false);
        }
        return result;
    }
};

// Time Complexity - O(n)
// Space Complexit - O(n)

// Method - 2
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector <bool> result;
        int max = *max_element(candies.begin(), candies.end());
        for(int i=0; i<candies.size(); i++)
        {
            if((candies[i] + extraCandies) >= max)
                result.push_back(true);
            else result.push_back(false);
        }
        return result;
    }
};

// Time Complexity - O(n)
// Space Complexity - O(n)
