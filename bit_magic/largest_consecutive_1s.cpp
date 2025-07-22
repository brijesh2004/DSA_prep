class Solution {
  public:
    int maxConsecutiveOnes(int n) {
        // code here
        int ans = 0;
        int cnt = 0;
        while(n>0){
            if((n&1)==0){
                cnt = 0;
            }else{
                cnt++;
            }
            ans = max(ans , cnt);
            n = n>>1;
        }
        return ans;
    }
};