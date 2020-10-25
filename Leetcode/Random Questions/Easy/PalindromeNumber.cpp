class Solution
{
public:
    bool isPalindrome(int x)
    {
        // when x == 0 return true;
        if (x == 0)
            return true;

        // when x < 0 and x % 10 == 0 --> return false
        if (x < 0 or x % 10 == 0)
            return false;

        long reversed = 0; // to prevent overflow
        int pop = 0;
        while (x > reversed)
        {
            pop = x % 10;

            reversed = reversed * 10 + pop;

            x /= 10;

            if (!(reversed <= INT_MAX && reversed >= INT_MIN))
                return false;
        }

        if (reversed == x || x == reversed / 10)
            return true;
        return false;
    }
};

// Here we are comparing x and reversed till half the length of number
// In case of odd number we devide the reversed by 10 and then compare by value in x
// INT_MAX and INT_MIN used to check overflow condition