// User function Template for C++

class Solution {
  public:
    
    int findPalin(string &s , int i , int j, vector<vector<int>>&dp){
        if(i<0||j>=s.size()) return 0;
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int a=0, b=0,c=0;   
        if(s[i]==s[j]){
            a = 2+findPalin(s , i-1 , j+1 , dp);
        }else{
            b = findPalin(s , i-1, j , dp);
            c = findPalin(s , i,j+1 , dp);
        }
        return dp[i][j]=max(a , max(b,c));
    }
    int longestPalinSubseq(string &s) {
        // code here
        int ans = 0;
       int n = s.size();
       vector<vector<int>>dp(n+1 , vector<int>(n+1 , -1));
       for(int i=0;i<n;i++){
           // for odd length
           if((ans/2)>(n-i+1)) break;
           int a = findPalin(s , i , i , dp);
           int b = findPalin(s , i,i+1 , dp);
           ans = max(ans , max(a-1,b));
       }
       return ans;
    }
};


// Open https://www.geeksforgeeks.org/problems/longest-palindromic-subsequence-1612327878/1?page=1&sprint=24daafa10fb2e984858c0a965d12b11c&sortBy=submissions 