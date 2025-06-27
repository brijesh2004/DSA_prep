class Solution {
  public:
    void dfs(int node , vector<vector<int>>&adj ,unordered_map<int,bool>&vis , vector<int>&ans){
        vis[node]=true;
        ans.push_back(node);
        
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it,adj , vis , ans);
            }
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        
        vector<int>ans;
        unordered_map<int,bool>vis;
        dfs(0 , adj , vis , ans);
        return ans;
    }
};