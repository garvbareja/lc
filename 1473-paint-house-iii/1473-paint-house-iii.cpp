class Solution {
public:
    int dfs(vector<int>& houses,vector<vector<int>>& cost,int m,int n,int target,int index,int curnei,int lastcolor,vector<vector<vector<int>>> &dp){
        if(curnei>target){
            return INT_MAX/2;
        }
        if(index==m){
            return (curnei==target)?0:INT_MAX/2;
        }
        if(dp[index][curnei][lastcolor]!=-1) return dp[index][curnei][lastcolor];
        int res=1000001;
        if(houses[index]) res=min(res,dfs(houses,cost,m,m,target,index+1,(houses[index]==lastcolor)?curnei:curnei+1,houses[index],dp));
        else{
            for(int j=0;j<cost[index].size();j++)
                res=min(res,cost[index][j]+dfs(houses,cost,m,n,target,index+1,(j+1==lastcolor)?curnei:curnei+1,j+1,dp));
        }
        return dp[index][curnei][lastcolor]=res;
    }
    
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        vector<vector<vector<int>>> dp(houses.size(),vector<vector<int>>(target+1,vector<int>(n+1,-1)));
        int res=dfs(houses,cost,m,n,target,0,0,0,dp);
        if(res>=1000001) return -1;
        return res;
    }
};