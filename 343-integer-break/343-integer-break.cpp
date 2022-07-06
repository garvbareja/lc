class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1); dp[0]=0; dp[1]=1;
        for(int i=2;i<=n;i++)
            for(int num=1;num<=i/2;num++) dp[i]=max({dp[i],dp[num]*dp[i-num],num*dp[i-num],dp[num]*(i-num),(num*(i-num))});
        return dp[n];
    }
};