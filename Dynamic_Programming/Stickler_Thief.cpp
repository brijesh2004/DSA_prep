class Solution {
  public:
    int solve(vector<int>&arr , int ind , vector<int>&dp){
        if(ind>=arr.size()) return 0;
        
        if(dp[ind]!=-1) return dp[ind];
        // include
        int a = arr[ind]+solve(arr , ind+2 , dp);
        // exclude
        int b = solve(arr , ind+1 , dp);
        return dp[ind] = max(a , b);
    }
    
    int solveTab(vector<int>&arr){
        vector<int>dp(arr.size()+2 , 0);
        int n = arr.size();
        for(int i=n-1;i>=0;i--){
           int a = arr[i]+dp[i+2];
       
            int b = dp[i+1];
             dp[i] = max(a , b);
        }
        return dp[0];
    }
    int solveTabSpace(vector<int>&arr){
        int val1 = 0;
        int val2 = 0;
        int n = arr.size();
        for(int i=n-1;i>=0;i--){
           int a = arr[i]+val1;
            int b = val2;
            val1 = val2;
            val2 = max(a , b);
        }
        return val2;
    }
    int findMaxSum(vector<int>& arr) {
        // code here
        // vector<int>dp(arr.size()+2 , -1);
        // return solve(arr , 0 , dp);
        return solveTabSpace(arr);
    }
};

// open https://www.geeksforgeeks.org/problems/stickler-theif-1587115621/1?sortBy=&category%5B%5D=Dynamic%2520Programming&page=1&company%5B%5D=Amazon