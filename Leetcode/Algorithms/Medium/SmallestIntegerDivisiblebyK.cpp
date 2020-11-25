class Solution
{
public:
    int smallestRepunitDivByK(int K)
    {
        if (K % 2 == 0 || K % 5 == 0)
            return -1;

        int prev_rem = 0;

        for (int i = 1; i <= K; i++)
        {
            prev_rem = ((prev_rem * 10) + 1) % K;

            if (prev_rem == 0)
                return i;
        }

        return -1;
    }
};

// Time Complexity - O(K)
// Space Complexity - O(1)

// 111 = 110 + 1
// 111 % 6 = 110 % 6 + 1;

// 111 % 6 = 11%6 * 10 + 1%6;
// next_rem = (prev_rem * 10 + 1) % 6