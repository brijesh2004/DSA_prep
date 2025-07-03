class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        // code here
        int n = adj.size();
        
        vector<int>ans(n ,-1);
        
        queue<pair<int,int>>q;
        q.push({src, 0});
        vector<int>vis(n , false);
        while(!q.empty()){
            int node = q.front().first;
            int dist = q.front().second;
            q.pop();
            vis[node]=true;
            if(ans[node]==-1)
              ans[node]=dist;
            for(auto it:adj[node]){
                if(!vis[it]){
                    q.push({it , dist+1});
                    vis[node]=true;
                }
            }
        }
        return ans;
    }
};

