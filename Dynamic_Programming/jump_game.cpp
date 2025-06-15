// User function Template for C++

class Solution {
  public:
    // Function to check if we can reach the last index from 0th index.
    bool canReach(vector<int> &arr) {
        // code here
        if(arr[0]==0&&arr.size()!=1) return false;
       // if(arr[0]==0&&arr.size()==1) return true;
        
        int maxJump = arr[0];
        
        int n = arr.size();
        
        for(int i=1;i<n;i++){
           
           maxJump = max(i+arr[i],maxJump);
           //cout<<maxJump<<endl;
           if(maxJump>=n-1) return true;
           if(maxJump == i) return false;
        }
        return maxJump>=n-1?true:false;
        
        
    }
};


// open https://www.geeksforgeeks.org/problems/jump-game/1?page=1&sprint=24daafa10fb2e984858c0a965d12b11c&sortBy=submissions