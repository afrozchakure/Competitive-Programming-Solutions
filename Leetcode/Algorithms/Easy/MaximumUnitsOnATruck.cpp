class Solution
{
public:
    const static bool sortBySec(vector<int> &a, vector<int> &b)
    {
        return a[1] > b[1];
    }

    int maximumUnits(vector<vector<int>> &boxTypes, unsigned long long truckSize)
    {
        unsigned long long sum = 0;

        int count = 0;

        sort(boxTypes.begin(), boxTypes.end(), sortBySec);
        int i = 0;
        while (truckSize && i != boxTypes.size())
        {
            // cout<<boxTypes[i][0]<<" "<<boxTypes[i][1]<<endl;
            if (boxTypes[i][0] >= truckSize)
            {
                sum += (truckSize)*boxTypes[i][1];
                truckSize = 0;
            }
            else
            {
                sum += boxTypes[i][0] * boxTypes[i][1];
                truckSize -= boxTypes[i][0];
                // cout<<"TruckSize: "<<truckSize<<endl;
            }
            i++;
        }
        return sum;
    }
};