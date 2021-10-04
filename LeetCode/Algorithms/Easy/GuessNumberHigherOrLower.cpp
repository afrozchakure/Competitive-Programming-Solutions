// Brute force
// Simply iterate over the array and send check if each number
// gives guess(i) == 0, when found return i, else return the number

// Using Binary Search

/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution
{
public:
    int guessNumber(int n)
    {
        int start = 1;
        int end = n;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;

            if (guess(mid) == 0) // when mid == guess number
                return mid;

            // if num is lower than guess number
            if (guess(mid) == -1) // mid < guess number (our Number)
                end = mid - 1;

            // if num is higher than guess number
            if (guess(mid) == 1) // mid > guess number (our number)
                start = mid + 1;
        }
        return -1;
    }
};

// Time Complexity - O(logn)
// Space Complexity - O(1)