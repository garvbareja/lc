class Solution {
public:
    int search(vector<int>& nums, int t) {
        int low=0,high=nums.size()-1,mid;
        while(low<=high){
            mid=low+(high-low)/2;
            if(nums[mid]==t) return mid;
            if(nums[mid]>t) high=mid-1;
            else low=mid+1;
        }
        return -1;
    }
};