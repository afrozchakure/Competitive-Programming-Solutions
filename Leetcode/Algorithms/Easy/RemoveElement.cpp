// Method - 1 : TWo Pointers - when elements to remove are rare

class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int i = 0;
        int n = nums.size();

        while (i < n)
        {
            if (nums[i] == val)
            {
                nums[i] = nums[n - 1];
                n--;
            }
            else
                i++;
        }

        return n;
    }
};

/*
Algorithm

When we encounter nums[inums[i] = valnums[i]=val]=val, we can swap the 
current element out with the last element and dispose the last one. 
This essentially reduces the array's size by 1. Note that the last element 
that was swapped in could be the value you want to remove itself. 
But don't worry, in the next iteration we will still check this element.
*/

// Method - 1 : Two Pointers
class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int i = 0;

        for (int j = 0; j < nums.size(); j++)
        {
            if (nums[j] != val)
            {
                nums[i] = nums[j];
                i++;
            }
        }
        return i;
    }
};

// When nums[j] equals to the given value, skip this element by incrementing j.
// As long as nums[j]≠val, we copy nums[j] to nums[i] and  increment both indexes at the same time.
// Repeat the process until j reaches the end of the array and the new length is i.