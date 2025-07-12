class Solution {
  public:
    // Function to find the largest number after k swaps.
    string ans = "";
   void solve(string &s , int k , int ind){
    ans = max(ans, s);
    if(k == 0||ind==s.size()) return;

    for(int i = ind; i < s.size(); i++){
    if(s[i] > s[ind]){
        swap(s[ind], s[i]);
        solve(s, k-1, ind+1);
        swap(s[ind], s[i]);
    }
}
solve(s, k, ind+1);
}
    string findMaximumNum(string& s, int k) {
        // code here.
        ans = s;
        solve(s , k , 0);
        return ans;
    }
};