class Solution {
  public:
    // Function to find a solved Sudoku.
    bool isValid(int x , int y , vector<vector<int>>&mat , int val){
        if(x<=2&&y<=2){
            for(int i=0;i<=2;i++){
                for(int j=0;j<=2;j++){
                    if(mat[i][j]==val) return false;
                }
            }
        }
        else if(x<=2&&y<=5){
            for(int i=0;i<=2;i++){
                for(int j=3;j<=5;j++){
                    if(mat[i][j]==val) return false;
                }
            }
        }
        else if(x<=2&&y<=8){
            for(int i=0;i<=2;i++){
                for(int j=6;j<=8;j++){
                    if(mat[i][j]==val) return false;
                }
            }
        }
        else if(x<=5&&y<=2){
            for(int i=3;i<=5;i++){
                for(int j=0;j<=2;j++){
                    if(mat[i][j]==val) return false;
                }
            }
        }
        else if(x<=5&&y<=5){
            for(int i=3;i<=5;i++){
                for(int j=3;j<=5;j++){
                    if(mat[i][j]==val) return false;
                }
            }
        }
        else if(x<=5&&y<=8){
            for(int i=3;i<=5;i++){
                for(int j=6;j<=8;j++){
                    if(mat[i][j]==val) return false;
                }
            }
        }
        else if(x<=8&&y<=2){
            for(int i=6;i<=8;i++){
                for(int j=0;j<=2;j++){
                    if(mat[i][j]==val) return false;
                }
            }
        }
        else if(x<=8&&y<=5){
            for(int i=6;i<=8;i++){
                for(int j=3;j<=5;j++){
                    if(mat[i][j]==val) return false;
                }
            }
        }
        else if(x<=8&&y<=8){
            for(int i=6;i<=8;i++){
                for(int j=6;j<=8;j++){
                    if(mat[i][j]==val) return false;
                }
            }
        }
        
        for(int i=0;i<9;i++){
            if(mat[i][y]==val) return false;
            if(mat[x][i]==val) return false;
        }
        return true;
        return true;
    }
    
    bool solve(vector<vector<int>>& mat) {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (mat[i][j] == 0) { 
                for (int val = 1; val <= 9; ++val) { 
                    if (isValid(i, j, mat, val)) {
                        mat[i][j] = val; 
                        if (solve(mat)) { 
                            return true; 
                        } else {
                            mat[i][j] = 0; 
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}
    void solveSudoku(vector<vector<int>> &mat) {
        // code here
        solve(mat);
    }
};