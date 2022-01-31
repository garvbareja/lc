class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int n = arr.size();
        int temp = arr[n-1];
        int ans = 0;
        for( int i = n-2; i >= 0 ; i--){
            ans = max(ans, temp - arr[i]);
            temp = max(arr[i], temp);
        }
        return ans;
    }
};