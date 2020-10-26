class Solution
{
public:
    int mySqrt(int x)
    {
        int low = 0;
        int high = x;
        int result;
        if (x <= 1)
            return x;

        while (low <= high)
        {
            long mid = low + (high - low) / 2;

            // if mid * mid is equal to x
            if (mid * mid == x) // Avoid integer overflow here
                return mid;

            // if mid*mid is less than x
            if (mid * mid < x)
            {
                low = mid + 1;
                result = mid;
            }

            // If mid*mid is greater than x
            else
                high = mid - 1;
        }
        return result;
    }
};

// Time Complexity - O(logn) - Equal to time complexity of binary search
// Space Complexity - O(1) - Constant extra space is needed