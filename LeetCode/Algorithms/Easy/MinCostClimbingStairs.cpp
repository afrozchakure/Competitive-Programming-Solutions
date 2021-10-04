#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        for (int i = 2; i < cost.size(); i++)
        {
            cost[i] += min(cost[i - 1], cost[i - 2]);
        }
        return min(cost[cost.size() - 2], cost[cost.size() - 1]);
    }
};

class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int step1 = 0;
        int step2 = 0;
        for (int i = cost.size() - 1; i >= 0; i--)
        {
            int current_step = cost[i] + min(step1, step2);
            step1 = step2;
            step2 = current_step;
        }
        return min(step1, step2);
    }
};

// Time Complexity - O(N)
// Space Complexity - O(1)