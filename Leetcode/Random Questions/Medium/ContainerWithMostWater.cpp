class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int start = 0;
        int end = height.size() - 1;
        int max_area = 0;
        while (start < end)
        {
            if (height[start] < height[end])
            {
                max_area = max(max_area, height[start] * (end - start));
                start++;
            }
            else
            {
                max_area = max(max_area, height[end] * (end - start));
                end--;
            }
        }
        return max_area;
    }
};

// Time Complexity - O(n) -> It is the number of elements in the vector
// Space Complexity - O(1)

// Brute Force (Exceeced time limit)
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int max_area = 0;

        for (int i = 0; i < height.size(); i++)
        {
            for (int j = i + 1; j < height.size(); j++)
            {
                if (height[i] < height[j])
                {
                    max_area = max(max_area, height[i] * (j - i));
                }
                else
                {
                    max_area = max(max_area, height[j] * (j - i));
                }
            }
        }
        return max_area;
    }
};

// Time Complexity -O(n**2) --> calculating area of all (n*(n-1)/2) parts
// Space Complexity - O(1)