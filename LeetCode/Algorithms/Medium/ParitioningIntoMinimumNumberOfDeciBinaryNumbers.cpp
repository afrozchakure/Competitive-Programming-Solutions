class Solution
{
public:
    int minPartitions(string n)
    {
        int count = 0;
        int n_int = atoi(n);

        while (n_int > 0)
        {
            // calculate m (A number that has same
            // number of digits as n, but has 1 in
            // place of non-zero digits 0 in place
            // of 0 digits)
            int temp = n_int, m = 0, p = 1;
            while (temp)
            {
                int rem = temp % 10;
                temp = temp / 10;

                if (rem != 0)
                    m += p;

                p *= 10;
            }

            count++;
            // subtract m from n
            n_int = n_int - m;
        }
        return count;
    }
};