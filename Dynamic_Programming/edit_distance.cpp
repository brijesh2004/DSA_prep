class Solution {
  public:
    // Function to compute the edit distance between two strings
    
    int solve(string &s1 , string &s2 , int i,int j , vector<vector<int>>&dp){
         if (i == s1.size()) return s2.size() - j;
    if (j == s2.size()) return s1.size() - i;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(s1[i]==s2[j]){
            return solve(s1 , s2 , i+1 , j+1 , dp);
        }
        
            // insert
        int b = 1+solve(s1 , s2 , i,j+1 , dp);
            // remove the char from string
        int c = 1+solve(s1 , s2 , i+1 , j,dp);
         // replace a character
        int d = 1+solve(s1 , s2 , i+1 , j+1 , dp);
        
        return dp[i][j]=min(b , min(c,d));
    }
    int editDistance(string& s1, string& s2) {
        // code here
        vector<vector<int>>dp(s1.size()+1 , vector<int>(s2.size()+1 , -1));
        return solve(s1 , s2 , 0 , 0 , dp);
    }
};