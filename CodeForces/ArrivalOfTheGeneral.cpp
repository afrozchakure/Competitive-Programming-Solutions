#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> height(n);
    int max_height = INT16_MIN;
    int min_height = INT16_MAX;

    for (int i = 0; i < n; i++)
    {
        cin >> height[i];
        max_height = max(max_height, height[i]);
        min_height = max(min_height, height[i]);
    }

    for (int i = 0; i < n; i++)
    {
        if (height[i] == max_height)
        {
            int temp = height[i];
            height[i] = height[0];
            height[0] = temp;
        }
        if (height[i] == min_height)
        {
            int temp = height[i];
            height[i] = height[0];
            height[0] = temp;
        }
    }

    

    return 0;
}