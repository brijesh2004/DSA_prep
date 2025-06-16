class Solution {
  public:
  
   bool solve(string s , unordered_map<string , bool>&mp , int ind , unordered_map<int , bool>&dp){
    if(ind == s.size()) return true;
    if(dp.find(ind) != dp.end()) return dp[ind];

    string mid = "";
    for(int i = ind; i < s.size(); i++) {
        mid += s[i];
        if(mp.find(mid) != mp.end()) {
            if(solve(s, mp, i + 1, dp)) {
                return dp[ind] = true;
            }
        }
    }
    return dp[ind] = false;
}
    bool wordBreak(string &s, vector<string> &dictionary) {
        // code here
         unordered_map<string, bool> mp;
    for(auto &word : dictionary) {
        mp[word] = true;
    }

    unordered_map<int, bool> dp;
    return solve(s, mp, 0, dp);
    }
};


// open  https://www.geeksforgeeks.org/problems/word-break1352/1?page=2&company%5B%5D=Amazon&category%5B%5D=Dynamic%2520Programming&sortBy=