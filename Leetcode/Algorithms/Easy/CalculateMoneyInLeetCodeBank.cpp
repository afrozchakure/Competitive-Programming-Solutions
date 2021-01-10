class Solution
{
public:
    int totalMoney(int n)
    {
        int counter = 0;
        int sum = 0;
        int loop = n / 7;
        int temp = loop;
        int remaining = n % 7;
        if (n <= 7)
        {
            for (int i = 1; i <= n; i++)
            {
                sum += i;
            }
        }
        else if (n > 7)
        {
            while (loop--)
            {
                sum += (28 + (counter * 7));
                counter++;
                // cout<<"Mediator Sum: "<<sum<<endl;
            }
            // cout<<"Before sum: "<<sum<<endl;

            for (int i = 0; i < remaining; i++)
            {
                sum += (temp + 1);
                temp++;
            }
            // cout<<"Loop : "<<temp<<endl;

            // sum += remaining * (loop + 1);
        }
        return sum;
    }
};