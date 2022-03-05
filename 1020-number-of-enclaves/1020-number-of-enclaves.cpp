class Solution {
public:
    bool flag=true;
    int count=0;
    void dfs(vector<vector<int>>& grid,int i,int j){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || !grid[i][j]) return;
        if(i==0 || i==grid.size()-1 || j==0 || j==grid[0].size()-1) flag=false;
        grid[i][j]=0;count++;
        dfs(grid,i+1,j);
        dfs(grid,i,j+1);
        dfs(grid,i,j-1);
        dfs(grid,i-1,j);
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]){
                    count=0;
                    flag=true; dfs(grid,i,j);
                    if(flag) ans+=count;
                }
            }
        }
        return ans;
    }
};