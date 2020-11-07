// Here we do bit operation each time, we assign temp to the value of i and then check the condition
#include <string>
class Solution
{
public:
    vector<int> selfDividingNumbers(int left, int right)
    {
        vector<int> result;

        for (int i = left; i <= right; i++)
        {
            int temp = i;
            for (; temp > 0; temp /= 10)
            {
                if (temp % 10 == 0 || (i % (temp % 10)) > 0)
                    break;
            }
            if (temp == 0)
                result.push_back(i);
        }
        return result;
    }
};

// Time Complexity - O(n)
// Space Complexity -O(1)

#include <string>
class Solution
{
public:
    vector<int> selfDividingNumbers(int left, int right)
    {
        vector<int> result;

        for (int i = left; i <= right; i++)
            if (isDivisible(i))
                result.push_back(i);

        return result;
    }

    bool isDivisible(int num)
    {
        for (char &letter : to_string(num))
        {
            // cout << letter << " ";
            // Note: converting letter to integer gives the ascii value and hence doesn't workj
            if (letter == '0' || (num % (letter - '0')) > 0)
                return false;
        }
        // cout << endl;
        return true;
    }
};

// Time Complexity - O(n)
// Space Complexity - O(1), no extra space