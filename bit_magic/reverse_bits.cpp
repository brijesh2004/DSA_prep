class Solution {
  public:
    unsigned int reverseBits(unsigned int n) {
        // code here
       unsigned int ans = 0;
    
    while(n > 0) {
        ans <<= 1;         // Shift result to the left to make room
        ans |= (n & 1);    // Add the last bit of n to ans
        n >>= 1;           // Remove the last bit from n
    }
    
    return ans;
    }
};