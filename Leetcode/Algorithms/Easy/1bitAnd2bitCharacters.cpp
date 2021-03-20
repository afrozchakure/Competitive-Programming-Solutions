#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isOneBitCharacter(vector<int> &bits)
    {
        int i = 0;
        while (i < bits.size() - 1)
        {
            i += (bits[i] + 1);
        }

        return i == (bits.size() - 1);
    }
};
