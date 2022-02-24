class Solution {
public:
    int mod=1000000007; int mm,nn;
    vector<int> x={0,0,-1,1};
    vector<int> y={1,-1,0,0};
    vector<vector<vector<int>>> dp;
    int dfs(int moves,int i,int j){
        if(i<0 || i>=mm || j<0 || j>=nn) return 1;
        if(!moves) return 0;
        if(dp[moves][i][j]!=-1) return dp[moves][i][j];
        int ans=0;
        for(int z=0;z<4;z++) ans=(ans+dfs(moves-1,i+x[z],j+y[z]))%mod;
        return dp[moves][i][j]=ans;
    }
    
    int findPaths(int m, int n, int moves, int startx, int starty) {
        mm=m;nn=n;
        dp.resize(moves+1,vector<vector<int>>(m,vector<int>(n,-1)));
        return dfs(moves,startx,starty);
    }
};