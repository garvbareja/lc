class Solution {
public:
//     bool dfs(string &a,string &b,string &c,int i,int j,vector<vector<int>> &dp){
//         if(i==a.length() && j==b.length()) return true;
//         if(dp[i][j]!=-1) return dp[i][j];
//         if(i<a.length() && a[i]==c[i+j] && dfs(a,b,c,i+1,j,dp)) return dp[i][j]=true;
//         if(j<b.length() && b[j]==c[i+j] && dfs(a,b,c,i,j+1,dp)) return dp[i][j]=true;
//         return dp[i][j]=false;
//     }
    
//     bool isInterleave(string a, string b, string c) {
//         if(c.length()!=a.length()+b.length()) return false;
//         vector<vector<int>> dp(a.length()+1,vector<int>(b.length()+1,-1));
//         return dfs(a,b,c,0,0,dp);
//     }
    
    bool isInterleave(string a, string b, string c) {
        if(c.length()!=a.length()+b.length()) return false;
        vector<bool> prev(b.length()+1); vector<bool> cur(b.length()+1);
        prev.back()=true;
        for(int j=b.length()-1;j>=0;j--) if(b[j]==c[a.length()+j] && prev[j+1]) prev[j]=true;
        for(int i=a.length()-1;i>=0;i--){
            for(int j=b.length();j>=0;j--){
                if(j==b.length() && a[i]==c[i+j]) cur[j] = prev[j];
                else cur[j]=(a[i]==c[i+j] && prev[j])||(b[j]==c[i+j] && cur[j+1]);
            }
            prev=cur;
        }
        return prev[0];
    }
    
};