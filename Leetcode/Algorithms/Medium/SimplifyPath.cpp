class Solution
{
public:
    string simplifyPath(string path)
    {
        stringstream ss(path);
        string tmp, res;
        vector<string> stk;

        while (getline(ss, tmp, '/'))
        {
            if (tmp == "." || tmp == "")
                continue;
            if (tmp == ".." && !stk.empty())
                stk.pop_back();
            if (tmp != "..")
                stk.push_back(tmp);
        }

        for (auto &itr : stk)
        {
            res += "/" + itr;
        }

        return stk.empty() ? "/" : res;
    }
};

// Time Complexity - O(N)
// Space Complexity - O(N)