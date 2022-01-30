class Solution {
public:
    bool valid(vector<vector<int>>& mat,int i,int j){
        if(i<0 || i>=mat.size() || j<0 || j>=mat[i].size() || mat[i][j]==-1) return false;
        return true;
    }
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int,int>> q;
        vector<vector<int>> ans(mat.size(),vector<int>(mat[0].size()));
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(!mat[i][j]){
                    mat[i][j]=-1;
                    q.push({i,j});
                }
            }
        }
        int steps=0;
        vector<int> x={-1,1,0,0};
        vector<int> y={0,0,1,-1};
        while(!q.empty()){
            int size=q.size();
            while(size--){
                int i=q.front().first,j=q.front().second; q.pop();
                ans[i][j]=steps;
                for(int z=0;z<4;z++){
                    if(valid(mat,i+x[z],j+y[z])){
                        mat[i+x[z]][j+y[z]]=-1;
                        q.push({i+x[z],j+y[z]});
                    }
                }
            }
            steps++;
        }
        return ans;
    }
};