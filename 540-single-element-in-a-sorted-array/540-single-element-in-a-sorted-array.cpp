class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int low=0,high=nums.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int left=-1,right=100000000;
            if(mid-1>=0) left=nums[mid-1];
            if(mid+1<nums.size()) right=nums[mid+1];
            if(nums[mid]!=left && nums[mid]!=right) return nums[mid];
            if((left==nums[mid] && mid%2==0) || (nums[mid]==right && mid%2)) high=mid-1;
            else low=mid+1;
        }
        return -1;
    }
};