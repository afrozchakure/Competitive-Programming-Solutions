class Solution
{
public:
    string toLowerCase(string str)
    {
        string result = "";
        for (char &c : str)
        {
            if (isupper(c))
                result += (char)(c + 32);
            else
                result += c;
            cout << c << endl;
        }
        return result;
    }
};

// Time Complexity - O(n)
// Space Complexity - O(1)

// Just add 32 to the characters to convert them into lowercase

// Method - 2
class Solution {
public:
    string toLowerCase(string s) {
        // A - Z - 65 - 90
        // a - z - 97 - 122
        string result;
        int n= s.size();
        for(int i=0; i<n; i++)
        {
            if(s[i] - 'a' < 0 && s[i] <= 90 && s[i] >= 65)
            {
                result += char(s[i] - 'A' + 97);
                cout << char(s[i] - 'A' + 97);
            }
            else
            {
                result += s[i];
            }
        }
        return result;
    }
};

// Time Complexity - O(N) 
// Space Complexity - O(1)
