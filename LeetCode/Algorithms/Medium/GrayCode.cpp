class Solution {
public:
    vector<int> grayCode(int n) {
        vector<string> temp = getGrayCode(n);
        vector<int> ans;
        for(auto &i: temp)
        {
            ans.push_back(stoi(i, 0, 2));
        }
        return ans;
    }
    
    vector<string> getGrayCode(int n)
    {
        if(n == 1)
            return vector<string> {"0", "1"};
        
        vector<string> grayCodeOfPreviousNumber = getGrayCode(n-1);
        vector<string> res;
        
        int numberOfGrayCodesInPreviousNumber = grayCodeOfPreviousNumber.size();
        
        for(int i=0; i< numberOfGrayCodesInPreviousNumber; i++)
        {
            res.push_back("0" + grayCodeOfPreviousNumber[i]);
        }
        
        for(int i=numberOfGrayCodesInPreviousNumber - 1; i >= 0; i--)
        {
            res.push_back("1" + grayCodeOfPreviousNumber[i]);
        }
        
        return res;
    }
};

// Time Complexity - O(N), N is the input element
// Space Complexity - O(N), implicit stack
