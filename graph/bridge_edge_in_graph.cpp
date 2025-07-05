class Solution {
  public:
  
    void dfs(int node , unordered_map<int,vector<int>>&adj , vector<int>&vis){
        vis[node]=true;
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it , adj , vis);
            }
        }
    }
    
    bool isBridge(int V, vector<vector<int>> &edges, int c, int d) {
        // Code here
        unordered_map<int,vector<int>>adj;
        for(auto it:edges){
          if (!((it[0]==c && it[1]==d) || (it[0]==d && it[1]==c))){
                adj[it[0]].push_back(it[1]);
                adj[it[1]].push_back(it[0]);
            }
        }
        
        vector<int>vis(V , false);
        dfs(c , adj , vis);
        
        return vis[d];
    }
};