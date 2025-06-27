class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        // Code here
        
        queue<int>q;
        int s = adj.size();
        vector<bool>vis(s+1 , false);
        q.push(0);
        vis[0]=true;
        vector<int>ans;
    //    ans.push_back(0);
        
        while(!q.empty()){
            int front = q.front();
            q.pop();
            ans.push_back(front);
            for(auto it:adj[front]){
                if(!vis[it]){
                    q.push(it);
                    vis[it]=true;
                }
            }
        }
        return ans;
    }
};