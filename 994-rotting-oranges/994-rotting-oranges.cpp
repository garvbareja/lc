class Solution {
public:
    bool valid(vector<vector<int>>& grid,int i,int j){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[i].size() || grid[i][j]!=1) return false;
        return true;
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        int count=0;
        queue<pair<int,int>> q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==1) count++;
                if(grid[i][j]==2) q.push({i,j});
            }
        }
        if(!count) return 0;
        int mints=0;
        vector<int> x = {-1,1,0,0};
        vector<int> y = {0,0,1,-1};
        while(!q.empty()){
            mints++;
            int size=q.size();
            while(size--){
                int i=q.front().first,j=q.front().second; q.pop();
                for(int z=0;z<4;z++){
                    if(valid(grid,i+x[z],j+y[z])){
                        grid[i+x[z]][j+y[z]]=2;
                        q.push({i+x[z],j+y[z]});
                    }
                }
            }
            count-=q.size();
        }
        return count==0 ? mints-1:-1;
    }
};