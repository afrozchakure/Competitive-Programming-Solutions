#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution
{
    // chracter to digit mapping, and the inverse
    // (if you want better performance: use array instead of unordered_map)
    unordered_map<char, int> c2i;
    unordered_map<int, char> i2c;
    // limit: length of result
    int limit = 0;
    // digit: index of digit in a word, widx: index of a word in word list, sum: summation of all word[digit]
    bool helper(vector<string> &words, string &result, int digit, int widx, int sum)
    {
        if (digit == limit)
        {
            return sum == 0;
        }
        // if summation at digit position complete, validate it with result[digit].
        if (widx == words.size())
        {
            if (c2i.count(result[digit]) == 0 && i2c.count(sum % 10) == 0)
            {
                if (sum % 10 == 0 && digit + 1 == limit) // Avoid leading zero in result
                    return false;
                c2i[result[digit]] = sum % 10;
                i2c[sum % 10] = result[digit];
                bool tmp = helper(words, result, digit + 1, 0, sum / 10);
                c2i.erase(result[digit]);
                i2c.erase(sum % 10);
                return tmp;
            }
            else if (c2i.count(result[digit]) && c2i[result[digit]] == sum % 10)
            {
                return helper(words, result, digit + 1, 0, sum / 10);
            }
            else
            {
                return false;
            }
        }
        // if word[widx] length less than digit, ignore and go to next word
        if (digit >= words[widx].length())
        {
            return helper(words, result, digit, widx + 1, sum);
        }
        // if word[widx][digit] already mapped to a value
        if (c2i.count(words[widx][digit]))
        {
            if (digit + 1 == words[widx].length() && words[widx].length() > 1 && c2i[words[widx][digit]] == 0)
                return false;
            return helper(words, result, digit, widx + 1, sum + c2i[words[widx][digit]]);
        }
        // if word[widx][digit] not mapped to a value yet
        for (int i = 0; i < 10; i++)
        {
            if (digit + 1 == words[widx].length() && i == 0 && words[widx].length() > 1)
                continue;
            if (i2c.count(i))
                continue;
            c2i[words[widx][digit]] = i;
            i2c[i] = words[widx][digit];
            bool tmp = helper(words, result, digit, widx + 1, sum + i);
            c2i.erase(words[widx][digit]);
            i2c.erase(i);
            if (tmp)
                return true;
        }
        return false;
    }

public:
    bool isSolvable(vector<string> &words, string result)
    {
        limit = result.length();
        for (auto &w : words)
            if (w.length() > limit)
                return false;
        for (auto &w : words)
            reverse(w.begin(), w.end());
        reverse(result.begin(), result.end());
        return helper(words, result, 0, 0, 0);
    }
};

int main()
{
    int n;
    cin >> n;
    vector<string> words;

    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        words.push_back(str);
    }
    string result;
    cin >> result;

    Solution c;
    bool ans = c.isSolvable(words, result);
    if (ans == 1)
        cout << "true";
    else
        cout << "false";
    return 0;
}