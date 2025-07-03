class Solution {
  public:
  
    void dfs(int node ,int distance, unordered_map<int,vector<pair<int,int>>>&adj , vector<int>&dist){
        
        for(auto it:adj[node]){
            if(it.second+distance<dist[it.first]||dist[it.first]==-1){
                    dist[it.first]=it.second+distance;
                    dfs(it.first , it.second+distance , adj , dist);
            }
        }
    }
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        unordered_map<int ,vector<pair<int,int>>>adj;
        
        for(auto it:edges){
            adj[it[0]].push_back({it[1] , it[2]});
        }
        
        //vector<int>dist(V , INT_MAX);
        vector<int>dist(V , -1);
        
        // queue<pair<int,int>>q;
        // q.push({0,0});
        dist[0]=0;
        // while(!q.empty()){
        //     int node = q.front().first;
        //     int distance = q.front().second;
        //     q.pop();
        //     for(auto it:adj[node]){
        //         if(it.second+distance<dist[it.first]||dist[it.first]==-1){
        //             dist[it.first]=it.second+distance;
        //             q.push({it.first , it.second+distance});
        //         }
        //     }
        // }
        // for(int i=0;i<dist.size();i++){
        //     if(dist[i]==INT_MAX){
        //         dist[i]=-1;
        //     }
        // }
        dfs(0 , 0,adj , dist);
        return dist;
    }
};