class Solution {
  public:
  
    bool solve(int node , unordered_map<int , vector<int>>&adj , vector<bool>&vis , int n){
          if (n == 0) return true;
    vis[node] = true;

    for (auto it : adj[node]) {
        if (!vis[it]) {
            if (solve(it, adj, vis, n - 1)) return true;
        }
    }

    vis[node] = false;
    return false;
    }
    bool check(int n, int m, vector<vector<int>> edges) {
        // code here
        unordered_map<int , vector<int>>adj;
        
        for(int i=0;i<m;i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        for (int i = 1; i <= n; i++) {
    vector<bool> vis(n + 1, false);
    if (solve(i, adj, vis, n - 1)) return true;
}
return false;
        
    }
}