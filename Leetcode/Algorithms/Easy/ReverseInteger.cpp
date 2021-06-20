class Solution
{
public:
    int reverse(int x)
    {
        int reversed = 0; // Using long here, to avoid overflow
        int pop = 0;
        while (x > 0)
        {
            pop = x % 10;
            x = x / 10;
            reversed = reversed * 10 + pop;

            // Check whether reversed lies b/w INT_MAX && INT_MIN
            // if not return false
            if (!(reversed <= INT_MAX && reversed >= INT_MIN))
                return 0;
        }
        return reversed;
    }
};
