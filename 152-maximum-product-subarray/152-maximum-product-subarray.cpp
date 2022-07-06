class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int ans=nums[0],curmx=nums[0],curmn=nums[0];
        for(int i=1;i<nums.size();i++){
            int temp = curmn*nums[i];
            curmn=min(nums[i],min(temp,nums[i]*curmx));
            curmx=max(nums[i],max(temp,nums[i]*curmx));
            ans=max(ans,curmx);
        }
        return ans;
    }
};