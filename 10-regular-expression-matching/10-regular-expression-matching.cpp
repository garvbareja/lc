class Solution {
public:
    vector<vector<int>> dp;
    bool dfs(string& s,string& p,int i,int j){
        if(i>=s.length() && j>=p.length()) return true;
        if(j>=p.length()) return false;
        if(dp[i][j]!=-1) return dp[i][j];
        bool match = i<s.length() && (s[i]==p[j] || p[j]=='.');
        if(j+1<p.length() && p[j+1]=='*') if(dfs(s,p,i,j+2) || (match && dfs(s,p,i+1,j))) return dp[i][j]=1;
        if(match && dfs(s,p,i+1,j+1)) return dp[i][j]=1;
        return dp[i][j]=0;
    }
    
    bool isMatch(string s, string p){
        dp.resize(s.length()+1,vector<int>(p.length()+1,-1));
        return dfs(s,p,0,0);
    }
};