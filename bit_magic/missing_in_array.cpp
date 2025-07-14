class Solution {
  public:
    int missingNum(vector<int>& arr) {
        // code here
       int n = arr.size();
    long long int sum = (n + 1LL) * (n + 2LL) / 2;
    long long int sum1 = accumulate(arr.begin(), arr.end(), 0LL);
    return (int)(sum - sum1);
    }
};