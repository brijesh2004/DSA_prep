
class Solution {
  public:
    int binaryToInt(vector<int>&ans){
        int res = 0;
        reverse(ans.begin(),ans.end());
        for(int i=0;i<ans.size();i++){
            if(ans[i]==1){
                res+=pow(2,i);
            }
        }
        return res;
    }
    int minVal(int a, int b) {
        // code here
        vector<int>bits;
        while(a>0){
            int v = a%2;
            a=a/2;
            bits.push_back(v);
        }
        reverse(bits.begin() , bits.end());
        int bit = 0;
        while(b>0){
            int v = b%2;
            b = b/2;
            if(v==1) bit++;
        }
        vector<int>ans(bits.size(),0);
        
        
        // same same is equla to zero 
        for(int i=0;i<bits.size()&&bit>0;i++){
            if(bits[i]==1){
                ans[i]=1;
                bit--;
            }
        }
        int n = bits.size()-1;
        while(bit>0&&n>=0){
             if(ans[n]==0){
                 ans[n]=1;
                 bit--;
             }
             n--;
        }
        
        // binary to int
        int res = binaryToInt(ans);
        return res;
    }
};