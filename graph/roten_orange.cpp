class Solution {
  public:
    int orangesRotting(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();

    int totalFresh = 0;
    queue<vector<int>> q;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(mat[i][j] == 1) totalFresh++;
            else if(mat[i][j] == 2) q.push({i, j, 0});
        }
    }

    if(totalFresh == 0) return 0;

    int time = 0;
    while(!q.empty()){
        int x = q.front()[0];
        int y = q.front()[1];
        int tim = q.front()[2];
        q.pop();

        time = max(time, tim);

        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        for(int dir = 0; dir < 4; dir++){
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && mat[nx][ny] == 1){
                mat[nx][ny] = 2;
                totalFresh--;
                q.push({nx, ny, tim+1});
            }
        }
    }

    if(totalFresh > 0) return -1;
    return time;

    }
};