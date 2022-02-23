class Solution {
public:
    vector<vector<int>> dp;
    bool dfs(string& s,string& t,int i,int j){
        if(i==0) return true;
        if(j==0) return false;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i-1]==t[j-1]){
            if(dfs(s,t,i-1,j-1) || dfs(s,t,i,j-1)) return dp[i][j]=1;
            return dp[i][j]=0;
        }
        if(dfs(s,t,i,j-1)) return dp[i][j]=1;
        return dp[i][j]=0;
    }
    
    bool isSubsequence(string &s, string &t) {
        if(s.length()>t.length()) return false;
        dp.resize(s.length()+1,vector<int>(t.length()+1,-1));
        return dfs(s,t,s.length(),t.length());
    }
};