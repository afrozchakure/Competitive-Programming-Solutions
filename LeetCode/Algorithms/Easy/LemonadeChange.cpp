class Solution
{
public:
    bool lemonadeChange(vector<int> &bills)
    {
        int fives = 0;
        int tens = 0;

        for (int &bill : bills)
        {
            if (fives < 0)
                return false;
            if (bill == 5)
                fives++;
            else if (bill == 10)
            {
                fives--;
                tens++;
            }
            else if (tens > 0) // for $20 bill
            {
                tens--;
                fives--;
            }
            else // if only fives are available
            {
                fives -= 3;
            }
            if (fives < 0)
                return false;
        }

        return true;
    }
};

// Time Complexity - O(N)
// Space complexity - O(1)