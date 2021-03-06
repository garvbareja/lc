class Solution {
public:
    bool valid(vector<vector<int>>& mat,int i,int j){
        if(i<0|| i>=mat.size() || j<0 || j>=mat[i].size() || !mat[i][j]) return false;
        return true;
    }
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>> res(mat.size(),vector<int>(mat[0].size()));
        queue<pair<int,int>> q;
        for(int i=0;i<mat.size();i++)
            for(int j=0;j<mat[0].size();j++)
                if(!mat[i][j]) q.push({i,j});
        int steps=0;
        vector<int> x={-1,1,0,0};
        vector<int> y={0,0,1,-1};
        while(!q.empty()){
            int size=q.size();
            while(size--){
                int i=q.front().first; int j=q.front().second; q.pop();
                res[i][j]=steps;
                for(int z=0;z<4;z++)
                    if(valid(mat,i+x[z],j+y[z])){
                        q.push({i+x[z],j+y[z]});
                        mat[i+x[z]][j+y[z]]=0;
                    }
            }
            steps++;
        }
        return res;
    }
};