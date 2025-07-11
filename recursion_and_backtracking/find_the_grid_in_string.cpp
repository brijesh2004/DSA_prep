#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    bool solve(vector<vector<char>>&grid , string &word , int ind , int i,int j , int dir){
        if(ind==word.size()) return true;
        if(i<0||j<0||i>=grid.size()||j>=grid[0].size()||grid[i][j]!=word[ind]){
            return false;
        }
        if(dir==0){
            return solve(grid , word , ind+1 ,i-1 ,j , dir);
        }else if(dir==1){
            return solve(grid , word , ind+1 ,i+1 ,j , dir);
        }else if(dir==2){
            return solve(grid , word , ind+1 ,i ,j+1 , dir);
        }else if(dir==3){
            return solve(grid , word , ind+1 ,i ,j-1 , dir);
        }else if(dir==4){
            return solve(grid , word , ind+1 ,i+1 ,j+1 , dir);
        }else if(dir==5){
            return solve(grid , word , ind+1 ,i+1 ,j-1 , dir);
        }else if(dir==6){
            return solve(grid , word , ind+1 ,i-1 ,j+1 , dir);
        }
        return solve(grid , word , ind+1 ,i-1 ,j-1 , dir);
    }
    vector<vector<int>> searchWord(vector<vector<char>> grid, string word) {
        // Code here
        vector<vector<int>>ans;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==word[0]){
                    for(int dir=0;dir<=7;dir++){
                        if(solve(grid , word , 0 , i ,j ,dir)){
                            ans.push_back({i,j});
                            break;
                        }
                    }
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<vector<char>> grid = {
        {'a', 'b', 'c', 'd'},
        {'e', 'f', 'g', 'h'},
        {'i', 'j', 'k', 'l'}
    };
    string word = "abc";
    vector<vector<int>> result = sol.searchWord(grid, word);
    
    for (const auto& pos : result) {
        cout << "(" << pos[0] << ", " << pos[1] << ")" << endl;
    }
    
    return 0;
}