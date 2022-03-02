// class Solution {
// public:
//     int ans=0;
//     vector<int> x={0,0,1,-1};
//     vector<int> y={1,-1,0,0};
//     void dfs(vector<vector<int>>& grid,int i,int j){
//         if(!valid(grid,i,j) || grid[i][j]<0) return;
//         grid[i][j]=-1;
//         for(int z=0;z<4;z++) dfs(grid,i+x[z],j+y[z]);
//     }
    
//     bool valid(vector<vector<int>>& grid,int i,int j){
//         if(i<0 || i>=grid.size() || j<0 || j>=grid[i].size()) return false;
//         return true;
//     }
    
//     void bfs(vector<vector<int>>& grid,int sx,int sy){
//         queue<pair<int,int>> q; q.push({sx,sy});
//         grid[sx][sy]=-2;
//         while(!q.empty()){
//             int size=q.size();
//             while(size--){
//                 int i=q.front().first; int j=q.front().second; q.pop();
//                 if(grid[i][j]==-1) return;
//                 for(int z=0;z<4;z++){
//                     int ni=i+x[z]; int nj=j+y[z];
//                     if(valid(grid,ni,nj) && grid[i][j]!=-2){
//                         if(grid[ni][nj]==-1) return;
//                         grid[ni][nj]=-2;
//                         q.push({ni,nj});
//                     }
//                 }
//             }
//             ans++;
//         }
//     }
    
//     int shortestBridge(vector<vector<int>>& grid) {
//         bool flag=true;
//         for(int i=0;i<grid.size();i++){
//             for(int j=0;j<grid[i].size();j++){
//                 if(grid[i][j]){
//                     if(flag){
//                         dfs(grid,i,j);
//                         flag=false;
//                     }else{
//                         bfs(grid,i,j);
//                     }
//                 }
//             }
//         }
//         return ans;
//     }
// };
class Solution{
public:
    queue<pair<int,int>> q;
    int color;  bool flag=true;
    vector<int> x={1,-1,0,0};
    vector<int> y={0,0,1,-1};
    bool valid(vector<vector<int>>& grid,int i,int j){
        if(i<0 || i>=grid.size( )|| j<0 || j>=grid[i].size()) return false;
        return true;
    }
    
    void dfs(vector<vector<int>>& grid,int i,int j){
        if(!valid(grid,i,j) || grid[i][j]!=1) return;
        grid[i][j]=color;
        if(!flag) q.push({i,j});
        for(int z=0;z<4;z++) dfs(grid,i+x[z],j+y[z]);
    }
    
    int shortestBridge(vector<vector<int>>& grid){
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]){
                    if(flag){
                        color=2;
                        dfs(grid,i,j);
                        flag=false;
                    }
                    else{
                        color=3;
                        dfs(grid,i,j);
                    }
                }
            }
        }
        int ans=0;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                int i=q.front().first; int j=q.front().second; q.pop();
                if(grid[i][j]==2) return ans;
                for(int z=0;z<4;z++){
                    int ni=i+x[z]; int nj=j+y[z];
                    if(valid(grid,ni,nj) && grid[ni][nj]!=4){
                        if(grid[ni][nj]==2) return ans;
                        grid[ni][nj]=4;
                        q.push({ni,nj});
                    }
                }
            }
            ans++;
        }
        return ans;
    }
};