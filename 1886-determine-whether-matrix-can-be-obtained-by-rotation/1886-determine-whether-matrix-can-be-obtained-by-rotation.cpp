class Solution {
public:
    void rotate(vector<vector<int>>& nums) {
        int top=0,left=0,right=nums.size()-1,bottom=nums.size()-1;
        while(top<bottom && left<right){
            for(int i=0;i<right-left;i++){
                int topleftval=nums[top][left+i];
                nums[top][left+i]=nums[bottom-i][left];
                nums[bottom-i][left]=nums[bottom][right-i];
                nums[bottom][right-i]=nums[top+i][right];
                nums[top+i][right]=topleftval;
            }
            left++; right--; top++; bottom--;
        }
    }
    
    bool match(vector<vector<int>>& mat, vector<vector<int>>& target){
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){ 
                if(mat[i][j]!=target[i][j]) return false;
            }
        }
        return true;
    }
    
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int time=3;
        if(match(mat,target)) return true;
        while(time--){
            rotate(mat);
            if(match(mat,target)) return true;
        }
        return false;
    }
};