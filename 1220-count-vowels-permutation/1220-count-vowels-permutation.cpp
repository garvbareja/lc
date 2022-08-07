class Solution {
public:
    int mod=1e9+7;
    vector<vector<int>> dp;
    int dfs(int prev,int n){
        if(!n) return 1;
        if(dp[prev][n]!=-1) return dp[prev][n];
        int ans=0;
        if(prev==0){
            ans=(dfs(1,n-1))%mod;
        }else if(prev==1){
            ans=(dfs(0,n-1))%mod;
            ans=(ans+dfs(2,n-1)%mod)%mod;
        }else if(prev==2){
            ans=(ans+dfs(0,n-1)%mod)%mod;
            ans=(ans+dfs(1,n-1)%mod)%mod;
            ans=(ans+dfs(3,n-1)%mod)%mod;
            ans=(ans+dfs(4,n-1)%mod)%mod;
        }else if(prev==3){
            ans=(ans+dfs(2,n-1)%mod)%mod;
            ans=(ans+dfs(4,n-1)%mod)%mod;
        }else{
            ans=(ans+dfs(0,n-1)%mod)%mod;
        }
        return dp[prev][n]=ans;
    }
    
    int countVowelPermutation(int n) {
        dp.resize(5,vector<int>(n,-1));
        int ans=0;
        ans=(ans+dfs(0,n-1)%mod)%mod;
        ans=(ans+dfs(1,n-1)%mod)%mod;
        ans=(ans+dfs(2,n-1)%mod)%mod;
        ans=(ans+dfs(3,n-1)%mod)%mod;
        ans=(ans+dfs(4,n-1)%mod)%mod;
        return ans;
    }
};