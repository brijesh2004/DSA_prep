class Solution {
  public:
    
    
    int solve(string &s1 , string &s2 , int i , int j){
       if(i>=s1.size()||j>=s2.size()) return 0;
       if(s1[i]!=s2[j]) return 0;
       return 1+solve(s1 , s2 , i+1, j+1);
    }
    int longestCommonSubstr(string& s1, string& s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        
        vector<int>dp(n2+1 , 0);
        int ans = 0;
        for(int i=1;i<=n1;i++){
            vector<int>t(n2+1,0);
            for(int j=1;j<=n2;j++){
                if(s1[i-1]==s2[j-1]){
                    t[j] = dp[j-1]+1;
                }
                ans = max(ans , t[j]);
            }
            dp=t;
        }
        return ans;
    }
};

// open https://www.geeksforgeeks.org/problems/longest-common-substring1452/1?sortBy=&category%5B%5D=Dynamic%2520Programming&page=1&company%5B%5D=Amazon