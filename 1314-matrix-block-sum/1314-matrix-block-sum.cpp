class solve {
public:
    vector<vector<int>> dp;
    solve(vector<vector<int>>& matrix) {
        dp.resize(matrix.size()+1,vector<int>(matrix[0].size()+1));
        int above,runningsum;
        for(int i=0;i<matrix.size();i++){
            runningsum=0;
            for(int j=0;j<matrix[0].size();j++){
                above=dp[i][j+1];
                runningsum+=matrix[i][j];
                dp[i+1][j+1]=runningsum+above;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return dp[row2+1][col2+1]-dp[row1][col2+1]-dp[row2+1][col1]+dp[row1][col1];
    }
};

class Solution {
public:
    

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        solve *s=new solve(mat); int n=mat.size(); int m=mat[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mat[i][j]=s->sumRegion(max(0,i-k),max(0,j-k),min(n-1,i+k),min(m-1,j+k));
            }
        }
        return mat;
    }
};