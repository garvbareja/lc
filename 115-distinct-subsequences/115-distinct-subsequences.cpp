class Solution {
public:
    vector<vector<int>> dp;
    int dfs(string& s,string& t,int i,int j){
        if(j==t.length()) return 1;
        if(i==s.length()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]!=t[j]) return dp[i][j]=dfs(s,t,i+1,j);
        return dp[i][j]=dfs(s,t,i+1,j+1)+dfs(s,t,i+1,j);
    }
    
    int numDistinct(string &s,string &t){
        dp.resize(s.length(),vector<int>(t.length(),-1));
        return dfs(s,t,0,0);
    }
};