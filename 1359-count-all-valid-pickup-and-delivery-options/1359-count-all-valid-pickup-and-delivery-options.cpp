class Solution {
public:
    int mod=1e9+7;
    vector<vector<int>> dp;
    long dfs(int unpicked,int undelivered){
        if(unpicked==0 && undelivered==0) return 1;
        if(unpicked<0 || undelivered<0 || undelivered<unpicked) return 0;
        if(dp[unpicked][undelivered]!=-1) return dp[unpicked][undelivered];
        long ans=0;
        ans+=(unpicked*dfs(unpicked-1,undelivered)); ans%=mod;
        ans+=((undelivered-unpicked)*dfs(unpicked,undelivered-1)); ans%=mod;
        return dp[unpicked][undelivered]=ans;
    }
    
    int countOrders(int n) {
        dp.resize(n+1,vector<int>(n+1,-1));
        return dfs(n,n);
    }
};