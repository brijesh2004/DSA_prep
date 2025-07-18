class Solution {
  public:
    bool isPowerofTwo(int n) {
        // code here
        // for(int i=0;i<=n;i++){
        //     int val = pow(2 ,i);
        //     if(val==n) return true;
        //     if(val>n) return false;
        // }
        // return false;
        
        
        // bit magic
        
        while(n>1){
            if(n%2!=0) return false;
            n=n>>1;
        }
        return true;
    }
};