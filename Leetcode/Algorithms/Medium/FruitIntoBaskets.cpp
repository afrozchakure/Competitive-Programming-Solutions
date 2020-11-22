#include <iostream>
#include <vector>
#include <algorithm>
class Solution
{
public:
    int totalFruit(vector<int> &tree)
    {
        // find longest continguous subarrays of two numbers
        // Using a sliding window

        int last_fruit = -1;
        int second_last_fruit = -1;
        int last_fruit_count = 0;
        int current_max = 0;
        int max = 0;

        for (int fruit : tree)
        {
            // if current fruit == last fruit || current fruit == second last fruit
            if (fruit == last_fruit || fruit == second_last_fruit)
            {
                current_max += 1;
            }
            // When we are at the first element
            else
            {
                current_max = last_fruit_count + 1;
            }

            // When we are at the second element and both, the first and second elements match
            if (fruit == last_fruit)
            {
                last_fruit_count += 1;
            }
            // When both the elements are different
            else
            {
                last_fruit_count = 1;
                second_last_fruit = last_fruit;
                last_fruit = fruit;
            }

            max = max(current_max, max);
        }
        return max;
    }
};

// Time Complexity - O(n)
// Space Compelxity - O(1)