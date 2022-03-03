class Solution {
public:
    int row,col;
    vector<vector<int>> dp;
    int dfs(int i,int j){
        if(i<0 || i>=row || j<0 || j>=col) return 0;
        if(i==row-1 && j==col-1) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=0;
        ans+=dfs(i+1,j); ans+=dfs(i,j+1);
        return dp[i][j]=ans;
    }
    
    int uniquePaths(int m, int n){
        dp.resize(m,vector<int>(n,-1));
        row=m; col=n;
        return dfs(0,0);
    }
};