// Brute Force [Not accepted]

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution
{
public:
    int firstBadVersion(int n)
    {
        for (long i = 0; i < n; i++)
        {
            if (isBadVersion(i + 1))
            {
                return i + 1;
            }
        }
        return -1;
    }
};

// Time Complexity - O(n)
// Space Complexity - O(1)

// Using Binary Search (Accepted)

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution
{
public:
    int firstBadVersion(int n)
    {
        int left = 0;
        int right = n;

        while (left < right)
        {
            // To avoid overflow
            int mid = left + (right - left) / 2;

            if (isBadVersion(mid))
                right = mid;

            else
                left = mid + 1;
        }

        return left;
    }
};

// Time Complexity - O(logn)
// Space Complexity - O(1)

/*
Explanation: 
The only scenario left is where isBadVersion(mid) => true. 
This tells us that mid may or may not be the first bad version, but we can tell for sure that all versions 
after mid can be discarded. Therefore we set right=mid as the new search 
space of interval [left,mid] (inclusive).

In our case, we indicate leftleftleft and rightrightright as the boundary of our search space (both inclusive). 
This is why we initialize left=1 and right=n. 
*/