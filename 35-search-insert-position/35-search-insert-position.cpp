class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int floor=-1,i=0,j=nums.size()-1;
        while(i<=j){
            int mid = i +(j-i)/2;
            if(nums[mid]==target) return mid;
            if(nums[mid]<target){
                floor=mid;
                i=mid+1;
            }else{
                j=mid-1;
            }
        }
        return floor+1;
    }
};