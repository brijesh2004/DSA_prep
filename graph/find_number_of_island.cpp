class Solution {
  public:
  
    void solve(int i , int j , vector<vector<char>>&grid , vector<vector<bool>>&vis){
        if(i<0||j<0||i>=grid.size()||j>=grid[0].size()||vis[i][j]||grid[i][j]!='L') return;
        vis[i][j]=true;
        // now travers in eight direction
        solve(i+1,j, grid , vis);
        solve(i-1,j, grid , vis);
        solve(i,j+1, grid , vis);
        solve(i,j-1, grid , vis);
        solve(i+1,j+1, grid , vis);
        solve(i+1,j-1, grid , vis);
        solve(i-1,j+1, grid , vis);
        solve(i-1,j-1, grid , vis);
    }
    int countIslands(vector<vector<char>>& grid) {
        // Code here
        int row = grid.size();
        int col = grid[0].size();
        int ans = 0;
        vector<vector<bool>>vis(row, vector<bool>(col , false));
        
        
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]=='L')
                 {
                    if(!vis[i][j]){
                      solve(i , j ,grid , vis);
                      ans++;
                   }
                 }
            }
        }
        
        // for(auto it:land){
        //     if(!vis[it.first][it.second]){
        //         solve(it.first , it.second ,grid , vis);
        //         ans++;
        //     }
        // }
        
        
        return ans;
    }
};