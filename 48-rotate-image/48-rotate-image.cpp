class Solution {
public:
    void rotate(vector<vector<int>>& nums) {
        int left=0,top=0,right=nums.size()-1,bottom=nums.size()-1;
        while(left<right && top<bottom){
            for(int i=0;i<right-left;i++){
                int topleft=nums[top][left+i];
                nums[top][left+i]=nums[bottom-i][left];
                nums[bottom-i][left]=nums[bottom][right-i];
                nums[bottom][right-i]=nums[top+i][right];
                nums[top+i][right]=topleft;
            }
            top++; bottom--;
            right--; left++;
        }
    }
};