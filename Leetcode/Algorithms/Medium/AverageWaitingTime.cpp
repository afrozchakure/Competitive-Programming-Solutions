class Solution
{
public:
    double averageWaitingTime(vector<vector<int>> &customers)
    {
        double count = 0;
        unsigned long long arrivalTime = 0;
        unsigned long long waitingTime = 0;
        unsigned long long time = 0;
        unsigned long long previousTime = 0;
        for (int i = 0; i < customers.size(); i++)
        {
            arrivalTime = customers[i][0];
            time = customers[i][1];
            int totalTime = 0;
            if (arrivalTime <= previousTime)
            {
                totalTime = time + previousTime;
                // cout<<"\nTotal Time 1st Case "<<totalTime<<" "<<endl;
            }
            else
            {
                totalTime = arrivalTime + time;
                // cout<<"\nTotal Time 2nd Case "<<totalTime<<" "<<endl;
            }

            waitingTime += totalTime - arrivalTime;
            // cout<<waitingTime<<" ";

            previousTime = totalTime;
            count++;
        }
        double result = waitingTime / count;
        return result;
    }
};