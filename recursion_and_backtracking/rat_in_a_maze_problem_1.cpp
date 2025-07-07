class Solution {
  public:
    
    void solve(int i,int j , vector<vector<int>>&mat, string out , vector<string>&ans
    , vector<vector<bool>>&vis){
        if(i<0||j<0||i>=mat.size()||j>=mat[0].size()||mat[i][j]!=1||vis[i][j]){
            return ;
        }
        
       vis[i][j]=true;
        if(i==mat.size()-1&&j==mat[0].size()-1){
            ans.push_back(out);
            vis[i][j]=false;
            return;
        }
        
        solve(i+1 , j , mat , out+'D' , ans , vis);
        solve(i , j-1 , mat , out+'L' ,ans , vis);
        solve(i , j+1 , mat , out+'R' ,ans , vis);
        solve(i-1 , j , mat , out+'U' ,ans , vis);
       vis[i][j]=false;
    }
    
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        vector<string>ans;
        string output;
        vector<vector<bool>>vis(maze.size() , vector<bool>(maze[0].size() , false));
        solve(0 , 0 , maze , output , ans , vis);
        return ans;
    }
};