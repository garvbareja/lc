class Solution {
public:
    bool valid(vector<vector<int>>& nums,int i,int j){
        if(i<0 || i==nums.size() || j<0 || j==nums[i].size() || nums[i][j]) return false;
        return true;
    }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid){
        int n=grid.size();
        if(grid[n-1][n-1]==1 || grid[0][0]==1) return -1;
        if(grid.size()==1) return 1;
        vector<int> x = {1,-1,0,0,1,-1,-1,1};
        vector<int> y = {0,0,1,-1,1,1,-1,-1};
        queue<pair<int,int>> q; q.push({0,0});
        int step=1;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                int i=q.front().first; int j=q.front().second; q.pop();
                for(int z=0;z<8;z++){
                    int a=i+x[z]; int b=j+y[z];
                    if(valid(grid,a,b)){
                        if(a==n-1&&b==n-1) return step+1;
                        grid[a][b]=1;
                        q.push({a,b});
                    }
                }
            }
            step++;
        }
        return -1;
    }
};