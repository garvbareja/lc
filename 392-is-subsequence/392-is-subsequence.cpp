class Solution {
public:
    bool isSubsequence(string &s, string &t) {
        if(s.length()>t.length()) return false;
        vector<vector<bool>> dp(s.length()+1,vector<bool>(t.length()+1));
        for(int i=0;i<=s.length();i++){
            for(int j=0;j<=t.length();j++){
                if(i==0){
                    dp[i][j]=true; continue;
                }
                if(j==0){
                    dp[i][j]=false; continue;
                }
                if(s[i-1]==t[j-1]) dp[i][j]=(dp[i-1][j-1]||dp[i][j-1]);
                else dp[i][j]=dp[i][j-1];
            }
        }
        return dp[s.length()][t.length()];
    }
};