class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int low=0,high=nums.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int left=(mid+nums.size()-1)%nums.size();
            int right=(mid+1)%nums.size();
            if(nums[mid]<nums[left] && nums[mid]<nums[right]) return nums[mid];
            if(nums[mid]>nums[high]) low=mid+1;
            else high=mid-1;
        }
        return 0;
    }
};