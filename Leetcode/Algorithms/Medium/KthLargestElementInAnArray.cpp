#include <queue>
#include <vector>
class Solution
{
public:
    int showk(priority_queue<int> pq, int k)
    {
        priority_queue<int> dq = pq;

        int m = k - 1;
        while (m--)
        {
            cout << dq.top();
            dq.pop();
        }
        return dq.top();
    }
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int> pq;

        for (int &i : nums)
        {
            pq.push(i);
        }
        int ans = showk(pq, k);
        return ans;
    }
};

// Time Complexity - O(N)
// Space Complexity - O(N

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        return nums[n - k];
    }
};

// Time Complexity - O(nlogn)
// Space Complexity - O(k);