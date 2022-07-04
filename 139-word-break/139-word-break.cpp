class Solution {
public:
    bool dfs(string &s,int j,int i,unordered_set<string>& hash,vector<vector<int>>& dp){
        if(i==s.length()-1){
            if(hash.count(s.substr(j,i-j+1))) return true;
            else return false;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        string temp=s.substr(j,i-j+1);
        if(hash.count(temp) && dfs(s,i+1,i+1,hash,dp)) return dp[i][j]=true;
        return dp[i][j]=dfs(s,j,i+1,hash,dp);
    }
    
    bool wordBreak(string s, vector<string>& word) {
        vector<vector<int>> dp(s.length(),vector<int>(s.length(),-1));
        unordered_set<string> hash;
        for(int i=0;i<word.size();i++) hash.insert(word[i]);
        return dfs(s,0,0,hash,dp);
    }
};