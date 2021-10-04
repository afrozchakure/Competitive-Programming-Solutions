class Solution
{
public:
    string mostCommonWord(string para, vector<string> &banned)
    {
        {
            if (islapha(c))
        }
        unordered_set<string> s(para.begin(), para.end());
        unordered_map<string, int> map;

        for (auto &c : p)
        {
            if (isalpha(c))
            {
                c = tolower(c);
            }
            else
            {
                c = " ";
            }
        }
        for (string &element : para)
        {
            map[element] += 1;
        }

        int max_count = 0;
        string map_element = "";
        for (string &element : para)
        {
            if (max_count < map[element])
            {
                max_count = map[element];
                map_element = element;
            }
        }
        return map_element;
    }
};