class Solution {
public:
    int ans=0;
    void dfs(vector<vector<int>>& grid,int i,int j,int count){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]==-1) return;
        if(grid[i][j]==2){
            if(!count) ans++;
            return;
        }
        grid[i][j]=-1;
        dfs(grid,i+1,j,count-1);
        dfs(grid,i,j+1,count-1);
        dfs(grid,i-1,j,count-1);
        dfs(grid,i,j-1,count-1);
        grid[i][j]=0;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int count=1,startx,starty;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==0) count++;
                if(grid[i][j]==1){startx=i; starty=j;}
            }
        }
        dfs(grid,startx,starty,count);
        return ans;
    }
};