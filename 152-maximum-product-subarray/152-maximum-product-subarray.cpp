class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int curmin=nums[0],curmax=nums[0],res=nums[0];
        for(int i=1;i<nums.size();i++){
            int temp=nums[i]*curmax;
            curmax=max({nums[i],temp,nums[i]*curmin});
            curmin=min({nums[i],temp,nums[i]*curmin});
            res=max(res,curmax);
        }
        return res;
    }
};