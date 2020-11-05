// Solution 1
class Solution
{
public:
    vector<int> sortArrayByParity(vector<int> &A)
    {
        int start = 0;
        int end = A.size() - 1;
        while (start < end)
        {
            if (A[start] % 2 > A[end] % 2)
            {
                int temp = A[start];
                A[start] = A[end];
                A[end] = temp;
            }
            if (A[start] % 2 == 0)
                start++;
            if (A[end] % 2 == 1)
                end--;
        }
        return A;
    }
};

// Time Complexity - O(N), N is the length of A
//  Each step of the while loop makes j-i decrease by at least one.
// (Note that while quicksort is O(Nlog⁡N) normally,
// this is O(N) because we only need one pass to sort the elements.)

// Space Complexity - O(1), constant space

// Solution 2 - Brute Force (Extra Space)
class Solution
{
public:
    vector<int> sortArrayByParity(vector<int> &A)
    {
        vector<int> result;

        for (int &element : A)
        {
            if (element % 2 == 0)
                result.push_back(element);
        }

        for (int &element : A)
        {
            if (element % 2 == 1)
                result.push_back(element);
        }
        return result;
    }
};

// Time Copmlexity - O(n)
// Space Complexity - O(n)