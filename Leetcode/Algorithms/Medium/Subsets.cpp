#include <vector>
#include <iostream>
class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> output;
        vector<int> subset = {};
        generateSubsets(0, output, subset, nums);
        return output;
    }

    void generateSubsets(int index, vector<vector<int>> &output, vector<int> &subset, vector<int> &nums)
    {
        // Add the initial subset
        output.push_back(subset);

        for (int i = index; i < nums.size(); ++i)
        {
            // add i into the current combination
            subset.push_back(nums[i]);

            // use next integers to complete the combination
            generateSubsets(i + 1, output, subset, nums);

            // Backtracking
            subset.pop_back();
        }
    }
};

// Time Complexity - O(2*n), since we are making the decision whether
// to take the element or not take the element
// Space Complexity - O(n), since we are adding element to stack each time