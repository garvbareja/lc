class Solution {
public:
    bool flag=true;
    void dfs(vector<vector<int>>& m,vector<vector<int>>& n,int i,int j){
        if(i<0 || i>=m.size() || j<0 || j>=m[0].size() || !n[i][j]) return;
        if(!m[i][j]) flag=false;
        n[i][j]=0;
        dfs(m,n,i-1,j);
        dfs(m,n,i,j-1);
        dfs(m,n,i,j+1);
        dfs(m,n,i+1,j);
    }
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2){
        int islands=0;
        for(int i=0;i<grid1.size();i++){
            for(int j=0;j<grid1[i].size();j++){
                flag=true;
                if(grid2[i][j]){
                    dfs(grid1,grid2,i,j);
                    if(flag) islands++;
                }
            }
        }
        return islands;
    }
};