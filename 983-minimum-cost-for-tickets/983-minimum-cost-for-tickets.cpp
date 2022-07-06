class Solution {
public:
    int dfs(vector<int>& days,vector<int>& costs,int i,int pass,vector<vector<int>>& dp){
        if(i>=days.size()) return 0;
        if(dp[i][pass]!=-1) return dp[i][pass];
        if(days[i]<=pass) return dp[i][pass]=dfs(days,costs,i+1,pass,dp);
        else return dp[i][pass]=min({costs[0]+dfs(days,costs,i+1,days[i],dp),costs[1]+dfs(days,costs,i+1,days[i]+6,dp),costs[2]+dfs(days,costs,i+1,days[i]+29,dp)});
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<vector<int>> dp(days.size(),vector<int>(days.back()+30,-1));
        return dfs(days,costs,0,0,dp);
    }
};