class Solution
{
public:
    int numUniqueEmails(vector<string> &emails)
    {
        unordered_set<string> result;

        for (string &email : emails)
        {
            string cleanString = "";
            for (char &letter : email)
            {
                // Since we don't want either '+' or '@' in our local name
                if (letter == '+' || letter == '@')
                    break;
                if (letter == '.')
                    continue;
                cleanString += letter;
            }
            // email.find() function returns the position where the first '@' letter is found
            // later we use that position to find the next substring starting with '@' letter in 'email' string
            cleanString += email.substr(email.find('@'))
                               result.insert(cleanString);
        }
        return result;
    }
};

// Time Complexity - O(C), C is the total contents of the emails
// Space Complexity - O(C)