class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low=0,high=nums.size()-1;
        while(low<=high){
            int mid=low +(high-low)/2;
            int prev=INT_MIN; if(mid-1>=0) prev=nums[mid-1];
            int next=INT_MIN; if(mid+1<nums.size()) next=nums[mid+1];
            if(prev<nums[mid] && nums[mid]>next) return mid;
            if(prev>nums[mid]) high=mid-1;
            else low=mid+1;
        }
        return 0;
    }
};