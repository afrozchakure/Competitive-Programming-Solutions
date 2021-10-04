// Stack and Vector (Prefered and Easy approach)
// Depth First Search

// When visiting a room for the first time, look at all
// the keys in that room. For any key that hasn't been
// used yet, add it to the todo list (stack) for it to be used.

class Solution
{
public:
    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {
        int n = rooms.size();
        vector<bool> result(n, 0);
        // remember to initialize the values
        result[0] = 1;
        stack<int> s;
        s.push(0);

        while (!s.empty())
        {
            int temp = s.top();
            s.pop();
            for (int j : rooms[temp])
            {
                if (result[j] == 0)
                {
                    result[j] = 1;
                    s.push(j);
                    cout << j << " ";
                }
            }
            cout << endl;
        }

        for (bool visited : result)
        {
            cout << visited << " ";
            if (!visited)
                return false;
        }
        return true;
    }
};
// Time Complexity - O(N+E) -> N is the number of rooms and E is the no. of keys
// Space Complexity - O(N) --> to store stack s and vector result

// Using Stack and unordered Set
class Solution
{
public:
    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {
        stack<int> dfs;
        // remember to initialize the values
        unordered_set<int> seen = {0};

        dfs.push(0);
        while (!dfs.isempty())
        {
            int i = dfs.top();
            dfs.pop();
            for (int j : rooms[i])
            {
                if (dfs.count(j) == 0)
                {
                    dfs.push(j);
                    seen.insert(j);
                    if (seen.size() == dfs.size())
                        return true;
                }
            }
        }
        return seen.size() == dfs.size();
    }
};