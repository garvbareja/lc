class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int mn=nums[0]; int mx=nums[0];
        for(int i=0;i<nums.size();i++) mn=min(mn,nums[i]),mx=max(mx,nums[i]);
        if(mn+k<mx-k) return mx-k-mn-k;
        else return 0;
    }
};