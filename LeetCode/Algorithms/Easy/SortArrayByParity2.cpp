class Solution
{
public:
    vector<int> sortArrayByParityII(vector<int> &A)
    {
        int i = 0;
        int j = 1;
        int n = A.size();

        while (i < n && j < n)
        {
            while (i < n && A[i] % 2 == 0)
            {
                i += 2;
            }
            while (j < n && A[j] % 2 == 1)
            {
                j += 2;
            }

            if (i < n && j < n)
            {
                int temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
        }

        return A;
    }
};

// Time Complexity - O(n)
// Space Complexity - O(1)