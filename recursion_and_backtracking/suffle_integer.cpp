class Solution {

  public:

     void shuffleArray(int arr[], int n) {
        // Your code goes here
        int j = n/2;
        for(int i=0;i<n;i+=2,j++){
            int k = j;
            while(k>i+1){
                swap(arr[k] , arr[k-1]);
                k--;
            }
        }
    }
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