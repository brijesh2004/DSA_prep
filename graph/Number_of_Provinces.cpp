class Solution {
  public:
    void markasVis(unordered_map<int,vector<int>>&adj, int node ,vector<int>&vis){
        vis[node]=true;

        for(auto it:adj[node]){
            if(!vis[it]){
                markasVis(adj , it, vis);
            }
        }
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        unordered_map<int , vector<int>>ModAdj;
        
        for(int i=0;i<adj.size();i++){
            for(int j=0;j<adj[0].size();j++){
                if(adj[i][j]==1&&i!=j){
                    ModAdj[i].push_back(j);
                }
            }
        }
        
        vector<int>vis(V+1 , false);
        int ans = 0;
        for(int i=0;i<V;i++){
            if(!vis[i]) ans++;
            markasVis(ModAdj , i , vis);
        }
        return ans;
    }
};