#include <string>
#include <string>
class Solution
{
public:
    string licenseKeyFormatting(string S, int K)
    {
        string result;
        int num_of_char_after_dash = 0;
        transform(S.begin(), S.end(), S.begin(), ::toupper);
        for (int i = S.size() - 1; i >= 0; i--)
        {
            if (S[i] != '-')
            {
                if (num_of_char_after_dash != 0 && num_of_char_after_dash % K == 0)
                {
                    result += '-';
                    num_of_char_after_dash = 0;
                }
                result += S[i];
                num_of_char_after_dash++;
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

// Time Complexity - O(n), transform and reverse both have O(1) time complexity
// Space Complexity - O(1)