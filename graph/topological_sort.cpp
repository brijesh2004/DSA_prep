class Solution {
  public:
  
    void topoSort(int node , unordered_map<int , vector<int>>&adj , stack<int>&st , 
    vector<bool>&vis){
        vis[node]=true;
        
        for(auto it:adj[node]){
            if(!vis[it]){
                topoSort(it , adj , st , vis);
            }
        }
        st.push(node);
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        unordered_map<int , vector<int>>adj;
        
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        
        vector<bool>vis(edges.size() , false);
        stack<int>st;
        for(int i=0;i<V;i++){
          if(!vis[i])
            topoSort(i , adj , st ,vis);
        }
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
           // cout<<st.top()<<endl;
            st.pop();
        }
        return ans;
    }
};