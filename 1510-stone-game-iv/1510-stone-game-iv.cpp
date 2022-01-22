class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> dp(n+1);
        dp[0]=false;
        for(int i=1;i<=n;i++){
            int x=1;
            while(x*x<=i){
                if(!dp[i-(x*x)])
                    dp[i]=true;
                x++;
            }
        }
        return dp[n];
    }
};