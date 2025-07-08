class Solution {
  public:
    // Function to find all combinations of elements
    // in array arr that sum to target.
    
    void solve(int i , vector<int>&arr , int target , vector<int>&v,
    vector<vector<int>>&ans){
        if(target==0){
            ans.push_back(v);
            return;
        }
        if(target<0||i>=arr.size()) return ;
        
        v.push_back(arr[i]);
        solve(i , arr , target-arr[i] , v , ans);
        v.pop_back();
        solve(i+1 , arr , target , v, ans);
        
    }
    vector<vector<int>> combinationSum(vector<int> &arr, int target) {
        // Your code here
        vector<vector<int>>ans;
        vector<int>v;
        solve(0 , arr , target , v , ans);
        return ans;
        
    }
};