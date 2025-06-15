// User function Template for C++

class Solution {
  public:
    
    long long solve(int n , vector<long long>&dp){
        if(n<7) return n;
        
        if(dp[n]!=-1) return dp[n];
       long long int maxi = INT_MIN;
       for(int i=n-3;i>=1;i--){
           long long int v = solve(i , dp)*(n-i-1);
           maxi = max(maxi , v);
       }
       return dp[n] =  maxi;
    }
    long long solveTab(int n){
        if(n<=6) return n;
        vector<long long>dp(n+1 ,1);
        for(int i=0;i<7;i++){
            dp[i]=i;
        }
        
       for(int i=7;i<=n;i++){
            for(int j=n-3;j>=1;j--){
              long long int v = dp[j]*(i-j-1);
               dp[i] = max(dp[i] , v);
           }
       }
       return dp[n];
        
        
    }
    long long int optimalKeys(int N) {
        // code here
    //     vector<long long>dp(N+1 , -1);
    //   return solve(N , dp);
    
    return solveTab(N);
    }
};

// open https://www.geeksforgeeks.org/problems/special-keyboard3018/1?page=1&sprint=24daafa10fb2e984858c0a965d12b11c&sortBy=submissions