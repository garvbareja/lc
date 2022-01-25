class Solution {
public:
    bool dfs(vector<vector<int>>& m,vector<vector<int>>& n,int i,int j){
        if(i<0 || i>=m.size() || j<0 || j>=m[0].size() || !n[i][j]) return true;
        bool flag = true;
        if(!m[i][j]) flag=false;
        n[i][j]=0;
        vector<int> x={-1,1,0,0};
        vector<int> y={0,0,1,-1};
        for(int z=0;z<4;z++){
            if(!dfs(m,n,i+x[z],j+y[z])) flag=false;
        }
        return flag;
    }
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2){
        int islands=0;
        for(int i=0;i<grid1.size();i++){
            for(int j=0;j<grid1[i].size();j++){
                if(grid1[i][j] && grid2[i][j])
                    if(dfs(grid1,grid2,i,j)) islands++;
            }
        }
        return islands;
    }
};