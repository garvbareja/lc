class Solution {
public:
    int dfs(vector<int>& satisfaction,int index,int cur_time,vector<vector<int>>& dp){
        if(index==satisfaction.size()) return 0;
        if(dp[index][cur_time]!=-1) return dp[index][cur_time];
        int choice1=dfs(satisfaction,index+1,cur_time,dp);
        int choice2=cur_time*satisfaction[index]+dfs(satisfaction,index+1,cur_time+1,dp);
        return dp[index][cur_time]=max(choice1,choice2);
    }
    
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        vector<vector<int>> dp(satisfaction.size(),vector<int>(satisfaction.size()+1,-1));
        return dfs(satisfaction,0,1,dp);
    }
};