class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        for(int i=0;i<mat.size();i++){
            int low=0,high=mat[i].size()-1;
            while(low<=high){
                int l=-1,r=-1,u=-1,d=-1;
                int mid=low+(high-low)/2;
                if(mid-1>=0) l=mat[i][mid-1];
                if(mid+1<mat[i].size()) r=mat[i][mid+1];
                if(i-1>=0) u=mat[i-1][mid];
                if(i+1<mat.size()) d=mat[i+1][mid];
                if(l<mat[i][mid] && r<mat[i][mid] && u<mat[i][mid] && d<mat[i][mid]) return {i,mid};
                if(l<r) low=mid+1;
                else high=mid-1;
            }
        }
        return {};
    }
};