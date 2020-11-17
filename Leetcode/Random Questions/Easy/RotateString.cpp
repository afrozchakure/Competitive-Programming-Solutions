// Method - 1
class Solution
{
public:
    bool rotateString(string A, string B)
    {
        return (A.size() == B.size() && (A + A).find(B) != -1);
    }
};

// Method - 2
class Solution
{
public:
    bool rotateString(string A, string B)
    {
        stack<char> s;

        if (A.size() != B.size())
            return false;

        if (A.size() == 0 && B.size() == 0)
            return true;

        for (int i = 0; i < A.size(); i++)
        {
            s.push(A[0]);
            A.erase(A.begin());
            A = A + s.top();
            if (A == B)
                return true;
            s.pop();
        }
        return false;
    }
};