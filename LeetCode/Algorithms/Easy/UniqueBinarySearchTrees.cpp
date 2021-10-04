class Solution
{
public:
    int numTrees(int n)
    {
        return catalanNumber(n);
    }

    int catalanNumber(int n)
    {
        int catalan[n + 1]; // To create variable length array
        // Called flexible array members

        catalan[0] = 1;
        catalan[1] = 1;

        for (int i = 2; i <= n; i++)
        {
            catalan[i] = 0;
            for (int j = 0; j < i; j++)
            {
                // Uses the concept of catalan Numbers
                catalan[i] += catalan[j] * catalan[i - j - 1];
            }
        }
        return catalan[n];
    }
};

// Time Complexity - O(n**2)
// Space Complexity - O(n)

// C(4) -> (C0 * C3) + (C1 * C2) + (C2 * C1) + (C3 * C0)
// Watch Tech Dose video on the topic