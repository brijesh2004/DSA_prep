int spanningTree(int V, vector<vector<int>> adj[]) {
        
         vector<int>key(V , INT_MAX);
        vector<bool>mst(V , false);
        
      // start the algorith
        key[0]=0;
        for(int i=0;i<V;i++){
            int mini = INT_MAX;
            int u;
            // find minimum node
            for(int j = 0;j<V;j++){
                if(!mst[j]&&key[j]<mini){
                    u = j;
                    mini = key[j];
                }
            }
            
            // make min node as true;
            mst[u] = true;
            // check its adjecent nodes
            
            for(auto it:adj[u]){
                int v = it[0];
                int w = it[1];
                if(mst[v]==false&& w<key[v]){
                    key[v] = w;
                }
            }
        }
        int ans = 0;
        for(int i=1;i<V;i++){
            ans+=key[i];
        }
        return ans;
        
    }