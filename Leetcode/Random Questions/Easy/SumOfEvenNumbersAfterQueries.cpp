class Solution
{
public:
    vector<int> sumEvenAfterQueries(vector<int> &A, vector<vector<int>> &queries)
    {
        int sum = 0;
        vector<int> result;

        // Taking the sum of only even numbers
        for (int &a : A)
        {
            if (a % 2 == 0)
                sum += a;
        }

        for (int i = 0; i < queries.size(); i++)
        {
            int val = queries[i][0];
            int index = queries[i][1];

            // Removing the value at index if it is even
            if (A[index] % 2 == 0)
                sum -= A[index];
            A[index] += val;
            // Adding the index value again if it is even
            if (A[index] % 2 == 0)
                sum += A[index];
            result.push_back(sum);
        }
        return result;
    }
};

// Time Complexity - O(N + Q), where N is the length of A
// and Q is the number of queries
// Space Complexity - O(Q)