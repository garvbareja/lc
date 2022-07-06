class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int curmn=0,curmx=0,mx=INT_MIN,mn=INT_MAX,sum=0;
        for(int i=0;i<nums.size();i++){
            curmn+=nums[i]; curmx+=nums[i];
            if(curmx>mx) mx=curmx;
            if(curmn<mn) mn=curmn;
            if(curmx<0) curmx=0;
            if(curmn>0) curmn=0;
            sum+=nums[i];
        }
        if(sum==mn) return mx;
        return max(mx,sum-mn);
    }
};