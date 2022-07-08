class Solution {
public:
    bool valid(vector<vector<int>>& grid,int i,int j){
        if(i<0 || j<0 || i>=grid.size() || j>=grid.size()) return false;
        return true;
    }
    
    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int,int>> q; int watercount=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]) q.push({i,j});
                else watercount++;
            }
        }
        if(!watercount || q.empty()) return -1;
        vector<int> x={1,-1,0,0};
        vector<int> y={0,0,1,-1};
        int dist=-1,i,j,ni,nj;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                i=q.front().first; j=q.front().second; q.pop();
                for(int z=0;z<4;z++){
                    ni=i+x[z]; nj=j+y[z];
                    if(valid(grid,ni,nj) && !grid[ni][nj]){
                        grid[ni][nj]=1;
                        q.push({ni,nj});
                    }
                }
            }
            dist+=1;
        }
        return dist;
    }
};