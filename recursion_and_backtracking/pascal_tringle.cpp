class Solution {
  public:
    
    vector<int> nthRowOfPascalTriangle(int n) {
        // code here
        if(n==1) return {1};
        vector<int>ans;
        ans.push_back(1);
        ans.push_back(1);
        for(int i=3;i<=n;i++){
            vector<int>temp;
            temp.push_back(1);
            for(int j=1;j<ans.size();j++){
                temp.push_back(ans[j-1]+ans[j]);
            }
            temp.push_back(1);
            ans = temp;
        }
        return ans;
    }
};