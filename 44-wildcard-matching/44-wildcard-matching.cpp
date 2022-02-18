class Solution {
public:
    vector<vector<int>> dp;
    int dfs(string& s,string& p,int i,int j){
        if(i>=s.length() && j>=p.length()) return 1;
        if(j>=p.length()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        bool match = i<s.length() && (s[i]==p[j] || p[j]=='?');
        if(p[j]=='*'){
            for(int z=i;z<=s.length();z++){
                if(dfs(s,p,z,j+1)) return dp[i][j]=1;
            }
        }else if(match && dfs(s,p,i+1,j+1)) return dp[i][j]=1; 
        return dp[i][j]=0;
    }
    bool isMatch(string &s, string &p){
        dp.resize(s.length()+1,vector<int>(p.length()+1,-1));
        return dfs(s,p,0,0);
    }
};