class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector <int> r;
        vector <vector<int>> res;
        findNumbers(candidates, res, r, target, 0);
        return res;
    }
    void findNumbers(vector<int>& arr, vector<vector<int> >& res, vector<int>& r, int sum, int i)
    {
        if(sum < 0) // if sum becomes negative
            return;
        if(sum == 0){  // if sum becomes zero
            res.push_back(r);
            return;
        }
            
        while(i < arr.size() && sum - arr[i] >= 0)  // if i less than arr size and sum - arr[i] >= 0
        {
            r.push_back(arr[i]); // add them to the list
            findNumbers(arr, res, r, sum-arr[i], i);
            i++;
            
            r.pop_back(); // backtracking
            
        }
        
    }
};
