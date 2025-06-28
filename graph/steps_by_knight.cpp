class Solution {
  public:
    int minStepToReachTarget(vector<int>& knightPos, vector<int>& targetPos, int n) {
        // Code here
        queue<vector<int>>q;
        
        vector<vector<bool>>vis(n+1,vector<bool>(n+1,false));
        
        q.push({knightPos[0],knightPos[1] , 0});
        
        while(!q.empty()){
            int x = q.front()[0];
            int y = q.front()[1];
            int step = q.front()[2];
           // cout<<x<<" "<<y<<" "<<step<<endl;
            q.pop();
            if(x==targetPos[0]&&y==targetPos[1]) return step;
            //cout<<"h"<<endl;
            if(x<0||y<0||x>n||y>n||vis[x][y]) continue;
            vis[x][y]=true;
           // cout<<"hello"<<endl;
            // now cover all directions
            q.push({x+2 , y+1, step+1});
            q.push({x+2 , y-1, step+1});
            q.push({x-2 , y+1, step+1});
            q.push({x-2 , y-1, step+1});
            q.push({x+1 , y+2, step+1});
            q.push({x-1 , y+2, step+1});
            q.push({x+1 , y-2, step+1});
            q.push({x-1 , y-2, step+1});
        }
        return -1;
    }
};