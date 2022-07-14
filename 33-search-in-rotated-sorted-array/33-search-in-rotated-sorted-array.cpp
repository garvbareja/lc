class Solution {
public:
    int find_pivot(vector<int>& nums){
        int low=0,high=nums.size()-1,mid,res;
        while(low<=high){
            mid=low+(high-low)/2;
            int left=INT_MAX;
            if(mid-1>=0) left=nums[mid-1];
            int right=INT_MAX;
            if(mid+1<nums.size()) right=nums[mid+1];
            if(nums[mid]<left && nums[mid]<right) return mid;
            if(nums[low]>nums[mid]) high=mid-1;
            else if(nums[high]<nums[mid]) low=mid+1;
            else return low;
        }
        return 0;
    }
    
    int bs(vector<int>& nums,int target,int low,int high){
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
        int pivot=find_pivot(nums);
        int res=bs(nums,target,0,pivot-1);
        if(res==-1) res=bs(nums,target,pivot,nums.size()-1);
        return res;
    }
};