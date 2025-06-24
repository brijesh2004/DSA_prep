class Solution {
  public:
    int solve(vector<int>&coins , int sum , int ind , vector<vector<int>>&dp){
        if(ind>=coins.size()||sum<0){
            return 0;
        }
        if(sum==0){
            return 1;
        }
        if(dp[sum][ind]!=-1){
            return dp[sum][ind];
        }
        // include
        int a = solve(coins , sum-coins[ind] , ind,dp);
        // exclude
        int b = solve(coins , sum , ind+1, dp);
        return dp[sum][ind] = a+b;
    }
    
    int solve(vector<int>&coins , int sum){
        int n = coins.size();
       vector<vector<int>> dp(sum + 1, vector<int>(n + 1, 0));

    // Base case: There is 1 way to make sum 0 (no coins)
        for (int i = 0; i <= n; i++) {
           dp[0][i] = 1;
        }

    // Fill the table
    for (int s = 1; s <= sum; s++) {
        for (int i = n - 1; i >= 0; i--) {
            int take = (s - coins[i] >= 0) ? dp[s - coins[i]][i] : 0;
            int skip = dp[s][i + 1];
            dp[s][i] = take + skip;
        }
    }

    return dp[sum][0];
    }
    int count(vector<int>& coins, int sum) {
        // code here.
        // vector<vector<int>>dp(sum+1 , vector<int>(coins.size()+1,-1));
        // return solve(coins , sum , 0 , dp);
        return solve(coins , sum);
    }
};