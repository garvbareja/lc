class Solution {
public:
    int findMin(vector<int>& nums) {
        int low=0,high=nums.size()-1,mid,left,right;
        while(low<=high){
            mid=low+(high-low)/2;
            if(mid-1>=0) left=nums[mid-1];
            else left=INT_MAX;
            if(mid+1<nums.size()) right=nums[mid+1];
            else right=INT_MAX;
            if(left>nums[mid] && right>nums[mid]) return mid;
            if(nums[low]>nums[mid]) high=mid-1;
            else if(nums[high]<nums[mid]) low=mid+1;
            else return low;
        }
        return -1;
    }
    
    int bs(vector<int>& nums,int low,int high,int target){
        int mid;
        while(low<=high){
            mid=low+(high-low)/2;
            if(nums[mid]==target) return mid;
            if(nums[mid]<target) low=mid+1;
            else high=mid-1;
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        int index=findMin(nums);
        int res=bs(nums,0,index-1,target);
        if(res==-1) res=bs(nums,index,nums.size()-1,target);
        return res;
    }
};