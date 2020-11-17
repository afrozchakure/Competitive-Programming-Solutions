class Solution
{
public:
    int oddEvenJumps(vector<int> &A)
    {
        int n = A.size(), res = 1;
        vector<int> higher(n), lower(n);
        higher[n - 1] = lower[n - 1] = 1;
        map<int, int> map;
        map[A[n - 1]] = n - 1;
        for (int i = n - 2; i >= 0; i--)
        {
            auto hi = map.lower_bound(A[i]), lo = map.upper_bound(A[i]);

            if (hi != map.end())
                higher[i] = lower[hi->second];
            if (lo != map.begin())
                lower[i] = higher[(--low)->second];
            if (higher[i])
                res++;
            map[A[i]] = i;
        }

        return res;
    }
};