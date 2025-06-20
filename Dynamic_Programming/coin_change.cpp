class Solution {
  public:
    
    int solve(vector<int>&coins, int currSum , vector<int>&dp){
        if(currSum==0) return 0;
        if(currSum<0) return INT_MAX;
        
        if(dp[currSum]!=-1) return dp[currSum];
        
        int s = INT_MAX;
        for(int i=0;i<coins.size();i++){
            int k = solve(coins , currSum-coins[i] , dp);
            if(k!=INT_MAX){
                s = min(s , 1+k);
            }
        }
        return dp[currSum] = s;
    }
    
    
    
    int solveTab(vector<int>&coins , int sum){
           vector<int>dp(sum+1 ,INT_MAX);
        dp[0] = 0;
        for(int i=0;i<=sum;i++){
            for(int j=0;j<coins.size();j++){
                if(i-coins[j]>=0&&dp[i-coins[j]]!=INT_MAX){
                    dp[i] = min(dp[i],1+dp[i-coins[j]]);
                }
            }
        }
        if(dp[sum]==INT_MAX){
            return -1;
        }
        return dp[sum];
    }
    
    
    int minCoins(vector<int> &coins, int sum) {
        // code here
        sort(coins.begin() , coins.end() , greater<int>());
        // vector<int>dp(sum+1 , -1);
        // int ans = solve(coins , sum , dp);
        // return ans == INT_MAX?-1:ans;
        return solveTab(coins , sum);
    }

};

// open https://www.geeksforgeeks.org/problems/number-of-coins1824/1?sortBy=&category%5B%5D=Dynamic%2520Programming&page=1&company%5B%5D=Amazon