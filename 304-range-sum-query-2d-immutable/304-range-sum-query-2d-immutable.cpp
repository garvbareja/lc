class NumMatrix {
public:
    vector<vector<int>> prefix;
    NumMatrix(vector<vector<int>>& matrix) {
        prefix.resize(matrix.size(),vector<int>(matrix[0].size()));
        int cur=0;
        for(int i=0;i<matrix.size();i++){
            cur=0;
            for(int j=0;j<matrix[0].size();j++){
                cur+=matrix[i][j];
                prefix[i][j]=cur;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int res=0;
        for(int j=row1;j<=row2;j++){
            if(!col1) res+=prefix[j][col2];
            else res+=(prefix[j][col2]-prefix[j][col1-1]);
        }
        return res;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */