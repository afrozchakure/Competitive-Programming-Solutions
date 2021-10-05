class Solution
{
public:
    bool isNStraightHand(vector<int> &hand, int W)
    {
        if (hand.size() % W != 0)
            return false;
        map<int, int> m;

        for (int curr : hand)
            m[curr]++;

        while (m.size() != 0)
        {
            int current = m.begin()->first;
            for (int i = 0; i < W; i++)
            {
                if (m[current + i] == 0)
                    return false;
                else if (--m[current + i] < 1)
                    m.erase(current + i);
            }
        }
        return true;
    }
};

// Time Complexity - O(N * W)
// Space Complexity - O(N), N is the size of hand