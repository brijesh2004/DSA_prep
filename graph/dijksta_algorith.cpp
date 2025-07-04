class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<int>ans(V, INT_MAX);
        unordered_map<int,vector<pair<int,int>>>adj;
        
        
        for(auto it:edges){
            adj[it[0]].push_back({it[1] , it[2]});
            adj[it[1]].push_back({it[0] , it[2]});
        }
        priority_queue<pair<int,int> , vector<pair<int,int>> ,
        greater<pair<int,int>>>pq;
        
        pq.push({src , 0});
        ans[src] = 0;
        
        while(!pq.empty()){
            int node = pq.top().first;
            int dist = pq.top().second;
            pq.pop();
            for(auto it:adj[node]){
                if(ans[it.first]>dist+it.second){
                    ans[it.first] = dist+it.second;
                    pq.push({it.first , dist+it.second});
                }
            }
        }
        return ans;
    }
};