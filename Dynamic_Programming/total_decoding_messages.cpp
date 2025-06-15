class Solution {
  public:
  
    int solve(string &digits , int currInd , vector<int>&dp){
        // base case
        if(currInd>=digits.size()) return 1;
        
        if(dp[currInd]!=-1) return dp[currInd];
        int a = 0 , b=0;
        if(digits[currInd]!='0'){
            int currVal = digits[currInd]-'0';
            a = solve(digits , currInd+1 , dp);
            
            if(currInd+1<digits.size()){
                int twoSum = (digits[currInd]-'0')*10+(digits[currInd+1]-'0');
               // cout<<twoSum<<" a "<<endl;
               if(twoSum<=26)
                 b = solve(digits , currInd+2 , dp);
            }
        }
        return dp[currInd] = a+b;
    }
    int countWays(string &digits) {
        // Code here
        int n = digits.size();
        vector<int>dp(n+1 , -1);
        return solve(digits , 0 , dp);
    }
};


// open https://www.geeksforgeeks.org/problems/total-decoding-messages1235/1?page=1&sprint=24daafa10fb2e984858c0a965d12b11c&sortBy=submissions