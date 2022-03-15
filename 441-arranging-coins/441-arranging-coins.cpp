class Solution {
public:
    int arrangeCoins(int n) {
        int low=1,high=INT_MAX;
        int ans=1;
        while(low<=high){
            long long int mid=low+(high-low)/2;
            long long int coins=mid*(mid+1)/2;
            if(n==coins) return mid;
            if(n>coins){
                ans=mid;
                low=mid+1;
            }else high=mid-1;
        }
        return ans;
    }
};