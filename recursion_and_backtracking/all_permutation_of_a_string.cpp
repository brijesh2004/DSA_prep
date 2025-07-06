class Solution {
  public:
    
    void solve(int i, string &s , set<string>&ans){
    if(i == s.size()){
        ans.insert(s);
        return;
    }
    for(int j = i; j < s.size(); j++){
        swap(s[i], s[j]);
        solve(i + 1, s, ans);
        swap(s[i], s[j]);
    }
}
    vector<string> findPermutation(string &s) {
        // Code here there
        set<string>ans;
        
        solve(0 , s , ans);
        return vector<string>(ans.begin() , ans.end());
    }
};
