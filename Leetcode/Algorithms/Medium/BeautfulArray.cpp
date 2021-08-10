class Solution {
public:
    vector<int> beautifulArray(int n) {
        vector<int> result = {1};
        
        // result.push_back(1);
        
        while(result.size() < n)
        {
            vector<int> curr;
            
            for(int &num: result)
            {
                if((2 * num)- 1 <= n)
                    curr.push_back((2 * num) - 1);
            }
            for(int &num: result)
            {
                if((2 * num) <= n)
                    curr.push_back(2 * num);
            }
            result = curr;
        }
        return result;
    }
};

// Time Complexity - O(N), forms a logarithmic series
// Space Complexity - O(N)

// ---> A bit weird problem but can be solved using simple mathematics, see lee215's solution
