class Solution {
  public:
  
    bool isCycle(int node , unordered_map<int , vector<int>>&adj, vector<int>&vis , int parent){
        vis[node]=true;
        for(auto it:adj[node]){
            if(vis[it]&&parent!=it) return true;
            if(!vis[it]){
            bool cycle = isCycle(it , adj , vis , node);
            if(cycle) return true;
            }
        }
        return false;
    }
    
    
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        unordered_map<int,vector<int>>adj;
        
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>vis(V,false);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                bool cycle = isCycle(i , adj , vis , -1);
                //cout<<i<<" p "<<cycle<<endl;
                if(cycle) return true;
            }
        }
        return false;
        
    }
    
    
};