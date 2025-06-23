int solve(vector<int>&arr , int curr , bool canBuy , vector<vector<int>>&dp){
        if(curr>=arr.size()) return 0;
        
        if(dp[curr][canBuy]!=-1) return dp[curr][canBuy];
        // buy the stork
        if(canBuy){
         
           int buy = -arr[curr]+ solve(arr , curr+1 , false , dp);
           int nobuy = solve(arr , curr+1, true , dp);
           return dp[curr][canBuy]=max(buy , nobuy);
        }else{
            int sell = arr[curr] + solve(arr , curr+1 , true , dp);
            int nosell = solve(arr , curr+1 , false , dp);
            return dp[curr][canBuy]=max(sell , nosell);
        }
    }
    
    int solve(vector<int>&arr){
        vector<vector<int>>dp(arr.size()+1,vector<int>(2 , 0));
        
        for(int curr=arr.size()-1;curr>=0;curr--){
            for(int canBuy=0;canBuy<=1;canBuy++){
                if(canBuy){
                  int buy = -arr[curr]+ dp[curr+1][0];
                  int nobuy = dp[curr+1][1];
                  dp[curr][canBuy]=max(buy , nobuy);
                }else{
                  int sell = arr[curr] + dp[curr+1][1];
                  int nosell = dp[curr+1][0];
                  dp[curr][canBuy]=max(sell , nosell);
               }
            }
        }
        
        return dp[0][1];
    }
    
    int stockBuySell(vector<int> &arr) {
        // code here
        //vector<vector<int>>dp(arr.size()+1 ,vector<int>(2 , -1));
         //return solve(arr , 0 , true , dp);
         
         return solve(arr);
    }