class Solution {
  public:
    bool solve(vector<int>&arr , int ind , int sum , vector<vector<int>>&dp){
        if(sum==0) return true;
        if(sum<0) return false;
        if(ind>=arr.size()) return false;
        if(dp[ind][sum]!=-1) return dp[ind][sum];
        
        return dp[ind][sum]=solve(arr , ind+1 , sum-arr[ind] , dp) || 
        solve(arr , ind+1 , sum , dp);
    }
    
    bool solve(vector<int>&arr , int sum){
        vector<vector<int>>dp(arr.size()+1 , vector<int>(sum+1 , 0));
        for(int i=0;i<arr.size();i++){
            dp[i][0]=1;
        }
        
        for(int ind=arr.size()-1;ind>=0;ind--){
            for(int s = 1;s<=sum;s++){
                bool a = s-arr[ind]>=0?dp[ind+1][s-arr[ind]]:false;
                dp[ind][s]= a||dp[ind+1][s];
            }
        }
        return dp[0][sum];
    }
    bool equalPartition(vector<int>& arr) {
        // code here
        int sum = accumulate(arr.begin() , arr.end() , 0);
        
        if(sum%2!=0) return false;
        sum = sum/2;
        // vector<vector<int>>dp(arr.size()+1 , vector<int>(sum+1 , -1));
        // return solve(arr , 0 , sum , dp);
        return solve(arr , sum);
    }
};