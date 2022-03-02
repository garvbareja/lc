class Solution {
public:
    bool valid(vector<vector<char>>& maze,int i,int j){
        if(i<0 || i>=maze.size() || j<0 || j>=maze[i].size() || maze[i][j]=='+') return false;
        return true;
    }
    
    bool exit(vector<vector<char>>& maze,int i, int j){
        if(i==0 || i==maze.size()-1 || j==0 || j==maze[0].size()-1) return true;
        return false;
    }
    
    int nearestExit(vector<vector<char>>& maze, vector<int>& start) {
        queue<pair<int,int>> q; q.push({start[0],start[1]});
        maze[start[0]][start[1]]='+';
        vector<int> x={0,0,1,-1};
        vector<int> y={1,-1,0,0};
        int step=0;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                int i=q.front().first; int j=q.front().second; q.pop();
                for(int z=0;z<4;z++){
                    int ni=i+x[z]; int nj=j+y[z];
                    if(valid(maze,ni,nj)){
                        if(exit(maze,ni,nj)) return step+1;
                        q.push({ni,nj});
                        maze[ni][nj]='+';
                    }
                }
            }
            step++;
        }
        return -1;
    }
};