class Solution {
  public:
  
    bool isCycle(int node , unordered_map<int , vector<int>>&adj , vector<int>&vis , int parent){
        vis[node]=true;
        
        for(auto it:adj[node]){
            if(vis[it]) return true;
            bool cycle = isCycle(it , adj , vis , node);
            if(cycle) return true;
        }
        vis[node]=false;
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        unordered_map<int , vector<int>>adj;
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
        }
        
        vector<int>vis(V , false);
        for(int i=0;i<V;i++){
            bool cycle = isCycle(i , adj , vis , -1);
            if(cycle) return true;
        }
        return false;
        
    }
};