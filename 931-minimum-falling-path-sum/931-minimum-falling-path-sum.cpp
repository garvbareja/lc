class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans=INT_MAX;
        vector<int> prev(matrix.back().begin(),matrix.back().end());
        vector<int> cur(matrix[0].size());
        for(int i=matrix.size()-2;i>=0;i--){
            for(int j=matrix[i].size()-1;j>=0;j--){
                cur[j]=prev[j];
                if(j-1>=0) cur[j]=min(cur[j],prev[j-1]);
                if(j+1<matrix[i].size()) cur[j]=min(cur[j],prev[j+1]);
                cur[j]+=matrix[i][j];
            }
            prev=cur;
        }
        return *min_element(prev.begin(),prev.end());
    }
};