class Solution {
public:
    int compute(int actual,int exp){
        return actual-exp;
    }
    
    int findKthPositive(vector<int>& nums, int k) {
        if(nums[0]>k) return k;
        if(nums.back()==nums.size()) return nums.back()+k;
        int low=0,high=nums.size()-1,mid;
        while(low<=high){
            mid=low+(high-low)/2;
            int missing = compute(nums[mid],mid+1);
            if(missing>=k) high=mid-1;
            else low=mid+1;
        }
        int res=nums[high]+k-compute(nums[high],high+1);
        return res;
    }
};