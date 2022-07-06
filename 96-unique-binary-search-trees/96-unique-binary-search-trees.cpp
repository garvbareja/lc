class Solution {
public:
    vector<int> dp;
    int help(int n){
        if(dp[n]!=-1) return dp[n];
        int ans = 0;
        for(int i=1;i<=n;i++){
            ans+=(help(i-1)*help(n-i));
        }
        return dp[n]=ans; 
    }
    
    int numTrees(int n) {
        dp.resize(n+1,-1);
        dp[0]=1; dp[1]=1;
        return help(n);
    }
};