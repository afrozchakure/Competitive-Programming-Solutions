class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int i = nums.size() - 2;

        // First scan to find the first number greater than, number on the right
        while (i >= 0 && nums[i + 1] <= nums[i])
        {
            i--;
        }

        if (i >= 0)
        {
            int j = nums.size() - 1;
            // finding the first number greater than number[i], swapping them
            while (j >= 0 && nums[j] <= nums[i])
            {
                j--;
            }
            swap(nums, i, j);
        }

        reverse(nums, i + 1);
    }

    void reverse(vector<int> &nums, int start)
    {
        int i = start, j = nums.size() - 1;
        while (i < j)
        {
            swap(nums, i, j);
            i++;
            j--;
        }
    }
    void swap(vector<int> &nums, int i, int j)
    {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
};

// Time Complexity - O(n), in worst case only two scans of the whole array are needed
// Space Complexity - O(1), no extra space required

// 1. first find a[i] > a[i+1]
// 2. check first number where a[j] > a[i]

// 1 2 4 1
// 1 4 1 2 

// 1 2 4 3 
// 1 3 2 4 

// 4 3 2 1 
// 1 2 3 4 

// 1 2 3 4 
// 1 2 4 3 


// Swap the pair having lowest weightage to get Next greater 
// sequence

// 1 2 3 2 

// Special case 
// 1. DSC array 


// A strictly decreasing section is on its last permutation 
// like 6, 2, 1, 5, 4, 3, 0 
//      -------> <--------- 
// ans - 6, 2, 3, 0, 1, 4, 5 
// We need to modulate what is right before the strictly 
// decreasing section (0-, 1, 3, 4, 5)


// 1. find the point of change  
// 2. Find the number for substitution 
// 3. substitution is the next highest number in after the point of substituion 
// 4. For remaining array - Rearrange the numbers after swapping by either reversing and sorting. 