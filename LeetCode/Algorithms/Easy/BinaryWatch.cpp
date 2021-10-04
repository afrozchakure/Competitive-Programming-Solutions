class Solution
{
public:
    vector<string> readBinaryWatch(int num)
    {
        vector<string> result;
        for (int hours = 0; hours < 12; hours++)
        {
            for (int minute = 0; minute < 60; minute++)
            {
                string temp = "";
                if (__builtin_popcount(hours) + __builtin_popcount(minute) == num)
                {
                    temp += to_string(hours) + ":";
                    if (minute < 10)
                    {
                        temp += "0";
                    }
                    temp += to_string(minute);
                    result.push_back(temp);
                }
            }
        }
        return result;
    }
};