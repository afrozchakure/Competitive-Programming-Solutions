class RecentCounter
{
public:
    queue<int> q;
    RecentCounter()
    {
    }

    int ping(int t)
    {
        q.push(t);
        while (q.front() < (t - 3000))
            q.pop();

        return q.size();
    }
};

// Time Complexity - O(1)
// Space Complexity -O(1)