class Solution {
public:
    
    vector<vector<int>> output;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        
        vector<int> curr;
        dfs(0, curr, 0, target, candidates);
        return output;
    }
    
    void dfs(int i, vector<int>& curr, int total, int target, vector<int>& candidates)
    {
        if(total == target) 
        {
            output.push_back(curr);
            return;
        }
        
        if(i >= candidates.size() or total > target)
            return;
        
        // We first call the recursive function where the element is considered along with the total
        curr.push_back(candidates[i]);
        dfs(i, curr, total + candidates[i], target, candidates);
        
        // Next we remove the elment, increment the pointer to consider other elements
        curr.pop_back();
        dfs(i + 1, curr, total, target, candidates);
    }
};

// Time Complexity - O(2**T), T is the target value 
// Space Complexity - O(T), T is target value
