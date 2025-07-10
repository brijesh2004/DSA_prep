class Solution {

  public:
    void shuffleArray(int arr[], int n) {
        // Your code goes here
        
        int a[n];
        int j=0;
        for(int i=0;i<n/2;i++){
            a[j]=arr[i];
            j++;
            a[j]=arr[n/2+i];
            j++;
        }
        
        for(int i=0;i<n;i++){
            arr[i]=a[i];
        }
    }
};