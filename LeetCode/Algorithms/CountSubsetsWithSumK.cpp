int mod = (int)(1e9 + 7);
int f(vector<int> &arr, int ind, int sum, vector<vector<int>> &dp) {
	// if(sum == 0) return 1; 
	if(ind == 0) {
		if(sum == 0 && arr[0] == 0) return 2;   // 0 0 1 2 3, target = 5 - to handle case where multiple 0's
		if(sum == 0) return 1;  // 
		return arr[0] == sum; 
		// if(sum == 0 || sum == arr[0]) return 1; 
		// return 0; 
	}
	if(dp[ind][sum] != -1) return dp[ind][sum]; 
	// not take 
	int notTake = f(arr, ind - 1, sum, dp); 

	// take 
	int take = 0; 
	if(sum >= arr[ind]) {
		take = f(arr, ind -1, sum - arr[ind], dp); 
	}

	return dp[ind][sum] = (take + notTake) % mod; 
}

int findWays(vector<int>& arr, int k)
{
	// Write your code here.
	int n = arr.size(); 
	vector<vector<int>> dp(n, vector<int>(k + 1, -1)); 
	return f(arr, n-1, k, dp);
}


