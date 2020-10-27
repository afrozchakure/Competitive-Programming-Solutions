// Using Vector
class Solution
{
public:
    bool judgeCircle(string moves)
    {
        vector<int> point = {0, 0};
        for (char &c : moves)
        {
            if (c == 'U')
                point[1] += 1;
            if (c == 'D')
                point[1] -= 1;
            if (c == 'R')
                point[0] += 1;
            if (c == 'L')
                point[0] -= 1;
        }
        if (point[0] == 0 && point[1] == 0)
            return true;
        return false;
    }
};

// Time Complexity - O(n)
// Space Complexity - O(1)

// Using x and y integers
class Solution
{
public:
    bool judgeCircle(string moves)
    {
        int x = 0;
        int y = 0;
        for (char &c : moves)
        {
            if (c == 'U')
                y += 1;
            if (c == 'D')
                y -= 1;
            if (c == 'R')
                x += 1;
            if (c == 'L')
                x -= 1;
        }
        return (x == 0 && y == 0);
    }
};