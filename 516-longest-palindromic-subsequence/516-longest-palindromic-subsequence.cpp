class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string p=s; reverse(p.begin(),p.end());
        int dp[s.length()+1][p.length()+1];
        for(int i=0;i<=s.length();i++){
            for(int j=0;j<=p.length();j++){
                if(!i || !j){ dp[i][j]=0; continue;}
                if(s[i-1]==p[j-1]) dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[s.length()][p.length()];
    }
};