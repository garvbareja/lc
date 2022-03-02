class Solution {
public:
    vector<vector<vector<int>>> dp;
    int mod= 1e9 +7;
    vector<vector<int>> nums ={{1,2,3},{4,5,6},{7,8,9},{10,0,10}};
    int dx[8]={-2,-2,2, 2,-1,-1,1, 1};
    int dy[8]={1, -1,1,-1, 2,-2,2,-2};
    int dfs(int i,int j,int n){
        if(i<0 || i>=4 || j<0 || j>=3 || nums[i][j]>=10) return 0;
        if(!n) return 1;
        if(dp[i][j][n]!=-1) return dp[i][j][n]; 
        int ans=0;
        for(int k=0;k<8;++k)
        {
            int ni=i+dx[k];
            int nj=j+dy[k];
            ans+=dfs(ni,nj,n-1);
            ans%=mod;
        }
        return dp[i][j][n]=ans;
    }
    
    int knightDialer(int n) {
        int ans=0;
        dp.resize(4,vector<vector<int>>(3,vector<int>(n,-1)));
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums[i].size();j++){
                if(nums[i][j]<10){
                    ans+=dfs(i,j,n-1);
                    ans%=mod;
                }
            }
        }
        return ans;
    }
};