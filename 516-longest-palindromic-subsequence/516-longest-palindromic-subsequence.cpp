class Solution {
public:
    vector<vector<int>> dp;
    int lcs(string& s,string& p,int i,int j){
        if(i==s.length() || j==p.length()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==p[j]) return dp[i][j]=1+lcs(s,p,i+1,j+1);
        else return dp[i][j]=max(lcs(s,p,i+1,j),lcs(s,p,i,j+1));
    }
    
    int longestPalindromeSubseq(string s) {
        dp.resize(s.length(),vector<int>(s.length(),-1));
        string p =s;
        reverse(p.begin(),p.end());
        return lcs(s,p,0,0);
    }
};