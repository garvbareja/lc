class Solution {
public:
    int hIndex(vector<int>& nums) {
        int low=0,len=nums.size(),high=len-1;
        while(low<=high){
             int mid = low +(high-low)/2;
            if(nums[mid]==len-mid) return nums[mid];
            if(nums[mid]<len-mid) low=mid+1;
            else high=mid-1;
        }
        return len-low;
    }
};