class Solution {
  public:
  
    bool solve(string &s1 , string &s2 , string &s3 , int i , int j , vector<vector<int>>&dp){
        if (i == s1.size() && j == s2.size()) return true;
        if (dp[i][j] != -1) return dp[i][j];

        bool valid = false;

        if (i < s1.size() && s1[i] == s3[i + j]) {
           valid = valid || solve(s1, s2, s3, i + 1, j, dp);
        }
        if (j < s2.size() && s2[j] == s3[i + j]) {
           valid = valid || solve(s1, s2, s3, i, j + 1, dp);
        } 

        return dp[i][j] = valid;
        
    }
    
    bool solveTab(string &s1 , string &s2 , string &s3){
         vector<vector<bool>>dp(s1.size()+1 , vector<bool>(s2.size()+1 , false));
         dp[s1.size()][s2.size()] = true;
         
         for(int i=s1.size();i>=0;i--){
             for(int j=s2.size();j>=0;j--){
                 
                  if (i == s1.size() && j == s2.size()) continue;
                  
                 bool valid = false;
                 if (s1[i] == s3[i + j]) {
                    valid = valid || dp[i+1][j];
                 }
                 if (s2[j] == s3[i + j]) {
                    valid = valid || dp[i][j + 1];
                  } 
                 dp[i][j] = valid;
             }
         }
         
         return dp[0][0];
         
    }
    bool isInterleave(string& s1, string& s2, string& s3) {
        // code here
        // vector<vector<int>>dp(s1.size()+1 , vector<int>(s2.size()+1 , -1));
        // return solve(s1 , s2 , s3 , 0 , 0 , dp);
        
        return solveTab(s1 , s2 , s3);
    }
};