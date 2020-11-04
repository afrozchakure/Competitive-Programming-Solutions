// Method - 1 Two pointer method

// We can use two pointers to read the positive and negative parts of the array -
// one pointer j in the positive direction, and another i in the negative direction.

// Now that we are reading two increasing arrays (the squares of the elements),
// we can merge these arrays together using a two-pointer technique.

class Solution
{
public:
    vector<int> sortedSquares(vector<int> &A)
    {
        int positive_counter = 0;
        int n = A.size();

        // The order of comparisons in the while loop should be the same, else gives error for [-1]
        while (positive_counter < n && A[positive_counter] < 0)
            positive_counter += 1;

        int negative_counter = positive_counter - 1;
        int counter = 0;

        vector<int> sorted_squares(n);
        while (negative_counter >= 0 && positive_counter < n)
        {
            if ((A[negative_counter] * A[negative_counter]) < (A[positive_counter] * A[positive_counter]))
            {
                sorted_squares[counter] = A[negative_counter] * A[negative_counter];
                negative_counter -= 1;
            }
            else
            {
                sorted_squares[counter] = A[positive_counter] * A[positive_counter];
                positive_counter += 1;
            }
            counter += 1;
        }

        while (negative_counter >= 0)
        {
            sorted_squares[counter] = A[negative_counter] * A[negative_counter];
            negative_counter -= 1;
            counter += 1;
        }

        while (positive_counter < n)
        {
            sorted_squares[counter] = A[positive_counter] * A[positive_counter];
            positive_counter += 1;
            counter += 1;
        }
        for (int i : sorted_squares)
            cout << i << " ";
        return sorted_squares;
    }
};

// Time Complexity - O(n)  -> where n is length of A
// Space Complexity - O(n)

// Method - 2 (By Sorting)
class Solution
{
public:
    vector<int> sortedSquares(vector<int> &A)
    {
        for (int i = 0; i < A.size(); i++)
            A[i] = pow(A[i], 2);
        sort(A.begin(), A.end());
        return A;
    }
};

// Time Complexity - O(logn) -> n is length of A
// Space Complexity - O(n)
