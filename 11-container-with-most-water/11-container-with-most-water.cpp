class Solution {
public:
    int maxArea(vector<int>& nums) {
        int i=nums.size()-1,j=0,ans=0;
        while(j<i){
            ans=max(ans,min(nums[i],nums[j])*(i-j));
            if(nums[j]<nums[i]) j++;
            else i--;
        }
        return ans;
    }
};