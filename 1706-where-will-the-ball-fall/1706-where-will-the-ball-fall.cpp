class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size(); vector<int> ball;
        for(int j=0;j<m;j++) ball.push_back(j);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(ball[j]!=-1){
                    int col=ball[j];
                    if(grid[i][col]==1){
                        if((col+1<m && grid[i][col+1]==-1) || col==m-1) ball[j]=-1;
                        else ball[j]+=1;
                    }else{
                        if((col-1>=0 && grid[i][col-1]==1) || col==0) ball[j]=-1;
                        else ball[j]-=1;
                    }
                }
            }
        }
        return ball;
    }
};