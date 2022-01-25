class Solution {
public:
    bool valid(vector<vector<char>>& grid,int i,int j){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[i].size() || grid[i][j]=='0') return false;
        return true;
    }
    
    void bfs(vector<vector<char>>& grid,int i,int j){
        queue<pair<int,int>> q; q.push({i,j}); grid[i][j]='0';
        vector<int> x={1,-1,0,0};
        vector<int> y={0,0,1,-1};
        while(!q.empty()){
            int a=q.front().first; int b=q.front().second; q.pop();
            for(int z=0;z<4;z++){
                if(valid(grid,a+x[z],b+y[z])){
                    grid[a+x[z]][b+y[z]]='0';
                    q.push({a+x[z],b+y[z]});
                }
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int islands=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]=='1'){
                    bfs(grid,i,j);
                    islands++;
                }
            }
        }
        return islands;
    }
};