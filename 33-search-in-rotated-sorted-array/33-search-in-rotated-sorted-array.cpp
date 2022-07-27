class Solution {
public:
    int bsmin(vector<int>& nums,int target){
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
    
    int bs(vector<int>& nums,int target,int low,int high){
        int mid;
        while(low<=high){
            mid=low+(high-low)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]<target) low=mid+1;
            else high=mid-1;
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        int minindex=bsmin(nums,target);
        int res=bs(nums,target,0,minindex-1);
        if(res!=-1) return res;
        else return bs(nums,target,minindex,nums.size()-1);
    }
};