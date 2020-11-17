#include <utility>
#include <vector>

unsigned int number(const std::vector<std::pair<int, int>> &busStops)
{
    int busOn = 0;
    int busOut = 0;
    int finalBus = 0;

    for (int i = 0; i < busStops.size(); i++)
    {
        busOn += busStops[i].first;
    }

    for (int i = 0; i < busStops.size(); i++)
    {
        busOut += busStops[i].second;
    }

    finalBus = busOn - busOut;

    return finalBus;
}