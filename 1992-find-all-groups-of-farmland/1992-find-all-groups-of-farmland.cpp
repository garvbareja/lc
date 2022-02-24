class Solution {
public:
    int ii,jj;
    vector<vector<int>> ans;
    vector<int> x={0,0,-1,1};
    vector<int> y={1,-1,0,0};
    
    void dfs(vector<vector<int>>& land,int i,int j){
        if(i<0 || i>=land.size() || j<0 || j>=land[i].size() || land[i][j]==0) return;
        land[i][j]=0; ii=max(ii,i); jj=max(jj,j);
        for(int z=0;z<4;z++) dfs(land,i+x[z],j+y[z]);
    }
    
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        for(int i=0;i<land.size();i++){
            for(int j=0;j<land[0].size();j++){
                if(land[i][j]==1){
                    ii=i; jj=j;
                    dfs(land,i,j);
                    ans.push_back({i,j,ii,jj});
                }
            }
        }
        return ans;
    }
};