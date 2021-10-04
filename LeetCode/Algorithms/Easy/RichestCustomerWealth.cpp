class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int max_money = 0;
        
        for(int i=0; i<accounts.size(); i++)
        {
            int sum = 0;
            for(int j=0; j<accounts[0].size(); j++)
            {
                sum += accounts[i][j];
            }
            max_money = max(max_money, sum);
        }
        return max_money;
    }
};
