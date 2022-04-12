class Solution {
public:
    int peakIndexInMountainArray(vector<int>& nums) {
        int low=0,high=nums.size()-1,left,right,mid;
        while(low<=high){
            mid=low+(high-low)/2;
            left=INT_MIN; if(mid-1>=0) left=nums[mid-1];
            right=INT_MIN; if(mid+1<nums.size()) right=nums[mid+1];
            if(left<nums[mid] && nums[mid]>right) return mid;
            if(left>nums[mid]) high=mid-1;
            else low=mid+1;
        }
        return -1;
    }
};