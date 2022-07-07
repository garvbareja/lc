class Solution {
public:
    bool dfs(string &a,string &b,string &c,int i,int j,vector<vector<int>> &dp){
        if(i==a.length() && j==b.length()) return true;
        if(dp[i][j]!=-1) return dp[i][j];
        if(i<a.length() && a[i]==c[i+j] && dfs(a,b,c,i+1,j,dp)) return dp[i][j]=true;
        if(j<b.length() && b[j]==c[i+j] && dfs(a,b,c,i,j+1,dp)) return dp[i][j]=true;
        return dp[i][j]=false;
    }
    
    bool isInterleave(string a, string b, string c) {
        if(c.length()!=a.length()+b.length()) return false;
        vector<vector<int>> dp(a.length()+1,vector<int>(b.length()+1,-1));
        return dfs(a,b,c,0,0,dp);
    }
    
    // bool isInterleave(string a, string b, string c) {
    //     if(c.length()!=a.length()+b.length()) return false;
    //     vector<vector<bool>> dp(a.length()+1,vector<bool>(b.length()+1));
    //     for(int i=a.length();i>=0;i--){
    //         for(int j=b.length();j>=0;j--){
    //             if(i==a.length() && j==b.length()) dp[i][j]=true;
    //             else{
    //                 if(i<a.length() && a[i]==c[i+j]) dp[i][j] = dp[i+1][j];
    //                 if(j<b.length() && b[j]==c[i+j]) dp[i][j] = dp[i][j+1];
    //             }
    //         }
    //     }
    //     return dp[0][0];
    // }
    
};