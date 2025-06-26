class Solution {
  public:
  
    int solve(int ind , int W , vector<int>&val , vector<int>&wt , vector<vector<int>>&dp){
        if(ind>=wt.size()||W<0) return 0;
        
        if(dp[ind][W]!=-1) return dp[ind][W];
        // include
        int a=0;
        if(W-wt[ind]>=0){
            a = val[ind]+solve(ind+1 , W-wt[ind] , val , wt , dp);
        }
        // not include
        int b = solve(ind+1 , W , val , wt , dp);
        return dp[ind][W] = max(a , b);
    }
    
    int solve(int W , vector<int>&val , vector<int>&wt){
        vector<vector<int>>dp(val.size()+1 , vector<int>(W+1 , 0));
        
        for(int i=wt.size()-1;i>=0;i--){
            for(int j=0;j<=W;j++){
                int a=0;
                if(j-wt[i]>=0){
                   a = val[i]+dp[i+1][j-wt[i]];
                }
                // not include
                int b = dp[i+1][j];
                dp[i][j] = max(a , b);
            }
        }
        return dp[0][W];
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        // vector<vector<int>>dp(val.size()+1 , vector<int>(W+1 , -1));
        // return solve(0 , W , val , wt , dp);
        return solve(W , val , wt);
    }
};