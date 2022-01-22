class Solution {
public:
    vector<int> dp;
    bool help(int n){
        if(n<=0) return false;
        if(dp[n]!=-1) return dp[n];
        for(int i=1;i*i<=n;i++){
            if(!help(n-(i*i))) return dp[n]=1; 
        }
        return dp[n]=0;
    }
    
    bool winnerSquareGame(int n) {
        dp.resize(n+1,-1);
        return help(n);
    }
};