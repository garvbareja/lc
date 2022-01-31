class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low=0,high=matrix.size()-1;
        int mid,floor=-1;
         while(low<=high){
             mid=low+(high-low)/2;
             if(matrix[mid][0]==target) return true;
             if(matrix[mid][0]>target) high=mid-1;
             else{
                 low=mid+1;
                 floor=mid;
             }
         } if(floor==-1) return false;
        mid=floor;
        low=0,high=matrix[0].size()-1;
        while(low<=high){
            floor=low+(high-low)/2;
            if(matrix[mid][floor]==target) return true;
            if(matrix[mid][floor]>target) high=floor-1;
            else low=floor+1;
        }
        return false;
    }
};