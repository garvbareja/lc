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
};