class Solution
{
public:
    int peakIndexInMountainArray(vector<int> &arr)
    {
        int low = 0;
        int high = arr.size() - 1;
        while (low < high)
        {
            int mid = low + (high - low) / 2;

            // This condition occurs when the first value is less
            // than second value, ie. when going up the mountain
            if (arr[mid] < arr[mid + 1])
                low = mid + 1;

            // This condition occurs when going down the mountain
            // or we are already on top of the mountain
            if (arr[mid] >= arr[mid + 1])
                high = mid;
        }
        return high;
    }
};

// Time Complexity - O(logN), N is the length of A
// Space Complexity - O(1)

class Solution
{
public:
    int peakIndexInMountainArray(vector<int> &arr)
    {
        int max = 0;
        int index = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] > max)
            {
                max = arr[i];
                index = i;
            }
        }
        return index;
    }
};

// Time Complexity - O(n)
// Space Complexity - O(1)