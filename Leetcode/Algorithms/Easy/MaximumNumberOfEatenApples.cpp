class Solution
{
public:
    int eatenApples(vector<int> &apples, vector<int> &days)
    {
        int n = days.size();
        // on ith day apple[i] rots after days[i]

        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            int timeTillRot = i + days[i];
            sum += apples;
        }

        if (sum < n)
        {
            return sum;
        }
    }
};
