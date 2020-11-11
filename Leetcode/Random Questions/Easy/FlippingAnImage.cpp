// Best solution
// First we iterate through each row and find the start and end pointer for each
// then we check if the start of array is equal to end of array
// If yes, we'll reverse the values in both elements
// After Flipping and inverting the image only those values which were equal for start and end
// pointer will change
class Solution
{
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            int start = 0;
            int end = A.size() - 1;
            while (start <= end)
            {
                if (A[i][start] == A[i][end])
                {
                    A[i][start] = 1 - A[i][start];
                    A[i][end] = A[i][start];
                }
                start++;
                end--;
            }
        }
        return A;
    }
};

// Time Complexity - O(n)
// Space Complexity - O(1)

// Other solution (Long solution)
// first flip the image and then invert the elements there itself
class Solution
{
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>> &A)
    {
        // flip image
        for (int i = 0; i < A.size(); i++)
        {
            int start = 0;
            int n = A[i].size() - 1;
            while (start <= n)
            {
                if (A[i][start] == 0)
                    A[i][start] = 1;
                else
                    A[i][start] = 0;
                if (start != n)
                {
                    if (A[i][n] == 1)
                        A[i][n] = 0;
                    else
                        A[i][n] = 1;
                }
                int temp = A[i][start];
                A[i][start] = A[i][n];
                A[i][n] = temp;

                start++;
                n--;
            }
        }
        return A;
    }
};

// Time Complexity - O(n)
// Space Complexity - O(1)