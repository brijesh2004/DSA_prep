class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.
    bool is_Possible(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();
        int x=0,y=0;
        // int a=b=0;
        // find the source and the destination point first
       for(int i=0;i<n;i++){
           for(int j=0;j<n;j++){
               if(grid[i][j]==1){
                   x = i;
                   y = j;
                   break;
               }
           }
       }
       
       // implementing the logic 
       
       queue<pair<int, int>>q;
       
       vector<vector<int>>visited(n,vector<int>(m,0));
       q.push({x,y});
       visited[x][y]=1;
        while(!q.empty()){
            pair<int, int>front = q.front();
            q.pop();
            int row = front.first;
            int col = front.second;
            if(grid[row][col]==2){
                return true;
            }
            // top 
            if(row-1>=0 && (grid[row-1][col]==3|| grid[row-1][col]==2)&&!visited[row-1][col]){
                visited[row-1][col] = 1;
                q.push({row-1 , col});
            }
             // down
            if(row+1<n && (grid[row+1][col]==3||grid[row+1][col]==2)&&!visited[row+1][col]){
                visited[row+1][col] = 1;
                q.push({row+1 , col});
            }
            // left
            if(col-1>=0 && (grid[row][col-1]==3||grid[row][col-1]==2)&&!visited[row][col-1]){
                visited[row][col-1] = 1;
                q.push({row, col-1});
            }
             // right
            if(col+1<m&& (grid[row][col+1]==3||grid[row][col+1]==2)&&!visited[row][col+1]){
                visited[row][col+1] = 1;
                q.push({row, col+1});
            }
            
        }
        return false;
    }
};