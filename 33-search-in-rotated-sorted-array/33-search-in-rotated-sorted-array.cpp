class Solution {
public:
    int bs_smallest(vector<int>& nums) {
        int low=0,high=nums.size()-1,left,right,mid;
        while(low<=high){
            mid=low+(high-low)/2;
            if(mid-1>=0) left=nums[mid-1];
            else left=INT_MAX;
            if(mid+1<nums.size()) right=nums[mid+1];
            else right=INT_MAX;
            if(nums[mid]<left && nums[mid]<right) return mid;
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
            if(nums[mid]<target) low++;
            else high--;
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        int index=bs_smallest(nums),res;
        
        res=bs(nums,0,index-1,target); if(res!=-1) return res;
        res=bs(nums,index,nums.size()-1,target); if(res!=-1) return res;
        return -1;
    }
};