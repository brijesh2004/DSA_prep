class Solution {
  public:

    // Function to find minimum number of attempts needed in
    // order to find the critical floor.
    int solve(int n , int k , vector<vector<int>>&dp){
        // base case
        if(k==1||k==0) return k;
        if(n==1) return k;
        
        if(dp[n][k]!=-1) return dp[n][k];
        
        int ans = INT_MAX;
        for(int i=1;i<=k;i++){
            int breakEgg = solve(n-1 , i-1 , dp);
            int notbreakEgg = solve(n , k-i , dp);
            ans = min(ans , 1+max(breakEgg,notbreakEgg));
        }
        
        return dp[n][k]=ans;
    }
    
    int solve(int n , int k){
       vector<vector<int>> dp(n+1 , vector<int>(k+1 , 0));

    // Base cases
    for(int i = 1; i <= n; i++) {
        dp[i][0] = 0;   
        dp[i][1] = 1;   
    }
    for(int j = 1; j <= k; j++) {
        dp[1][j] = j;   
    }

    for(int i = 2; i <= n; i++) {
        for(int j = 2; j <= k; j++) {
            dp[i][j] = INT_MAX;
            for(int x = 1; x <= j; x++) {
                int broken = dp[i-1][x-1];      
                int notBroken = dp[i][j-x];     
                int curr = 1 + max(broken, notBroken);
                dp[i][j] = min(dp[i][j], curr);
            }
        }
    }

    return dp[n][k];
    }
    
    
    int solveBinary(int n, int k) {
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

    for (int i = 1; i <= n; i++) {
        dp[i][0] = 0;
        dp[i][1] = 1;
    }

    for (int j = 1; j <= k; j++) {
        dp[1][j] = j;
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= k; j++) {
            int low = 1, high = j, res = INT_MAX;
            while (low <= high) {
                int mid = (low + high) / 2;
                int broken = dp[i - 1][mid - 1];
                int notBroken = dp[i][j - mid];
                int temp = 1 + max(broken, notBroken);

                // Binary search to minimize worst-case
                if (broken > notBroken) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }

                res = min(res, temp);
            }
            dp[i][j] = res;
        }
    }

    return dp[n][k];
}

    
    int eggDrop(int n, int k) {
        // code here
        //if(n==1) return k;
        // vector<vector<int>>dp(n+1 , vector<int>(k+1 , -1));
        // return solve(n ,k , dp);
        
        return solveBinary(n,k);
    } 
};