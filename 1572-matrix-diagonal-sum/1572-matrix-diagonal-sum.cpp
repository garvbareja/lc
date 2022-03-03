class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int i=0,j=0,sum=0;
        while(i<mat.size() && j<mat[i].size()) sum+=mat[i++][j++];
        i=0; j=mat[0].size()-1;
        while(i<mat.size() && j<mat[0].size()){
            if(i!=j) sum+=mat[i][j];
            i++; j--;
        }
        return sum;
    }
};