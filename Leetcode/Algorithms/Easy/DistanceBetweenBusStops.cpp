#include <vector>
#include <iostream>
using namespace std;
class Solution
{
public:
    int distanceBetweenBusStops(vector<int> &distance, int start, int destination)
    {
        int totalDistance = 0;
        int clockwiseDistance = 0;

        for (int i = 0; i < distance.size(); i++)
        {
            if (start < destination && (i >= start && i < destination))
                clockwiseDistance += distance[i];
            if (start > destination && (i >= start || i < destination))
                clockwiseDistance += distance[i];

            totalDistance += distance[i];
        }

        return min(clockwiseDistance, totalDistance - clockwiseDistance);
    }
};

// Time Complexity - O(N), since we are traversing the whole vector
// Space Complexity - O(1)