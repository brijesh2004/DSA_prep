class Solution {
  public:
    int isBitSet(int N) {
        // code here
        if(N==0) return 0;
        while(N>0){
           // cout<<(N&1)<<endl;
            if((N&1)==0) return 0;
            N=N>>1;
        }
        return 1;
    }
};