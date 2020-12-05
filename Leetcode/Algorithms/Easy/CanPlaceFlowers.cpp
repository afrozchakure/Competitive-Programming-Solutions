class Solution
{
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        int size = flowerbed.size();

        int count = 0;
        for (int i = 0; i < size; i++)
        {
            if (flowerbed[i] != 1 && (i == 0 || flowerbed[i - 1] != 1) && (i == size - 1 || flowerbed[i + 1] != 1))
            {
                count++;
                flowerbed[i] = 1;
            }
        }

        return count >= n;
    }
};

// Time Complexity - O(N)
// Space Complexity - O(1)