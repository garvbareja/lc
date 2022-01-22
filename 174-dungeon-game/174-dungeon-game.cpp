class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& g){
        int n=g.size(),m=g[0].size();
        vector<vector<int>> dp(n,vector<int>(m));
        if(g[n-1][m-1]<0) dp[n-1][m-1]=1-g[n-1][m-1];
        else dp[n-1][m-1] = 1;
        for(int i=n-2;i>=0;i--){
            if(dp[i+1][m-1]-g[i][m-1]>0) dp[i][m-1]=dp[i+1][m-1]-g[i][m-1];
            else dp[i][m-1]=1;  
        }
        for(int j=m-2;j>=0;j--){
            if(dp[n-1][j+1]-g[n-1][j]>0) dp[n-1][j]=dp[n-1][j+1]-g[n-1][j];
            else dp[n-1][j]=1;  
        }
        for(int i=n-2;i>=0;i--){
            for(int j=m-2;j>=0;j--){
                if(min(dp[i+1][j],dp[i][j+1])-g[i][j]>0) dp[i][j]=min(dp[i+1][j],dp[i][j+1])-g[i][j];
                else dp[i][j]=1;
            }
        }
        return dp[0][0];
    }
};