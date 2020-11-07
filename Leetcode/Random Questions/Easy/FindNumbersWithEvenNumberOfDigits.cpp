class Solution
{
public:
    int findNumbers(vector<int> &nums)
    {
        int count_even = 0;
        for (int &n : nums)
        {
            if (to_string(n).size() % 2 == 0)
                count_even += 1;
        }
        return count_even;
    }
};

// Converting the each number into a string and checking if the size
// of the string is even or not