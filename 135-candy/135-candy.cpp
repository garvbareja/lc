class Solution {
public:
    int candy(vector<int>& nums) {
        vector<int> candytmkc(nums.size(),1); int res=0;
        for(int i=1;i<nums.size();i++) if(nums[i]>nums[i-1]) candytmkc[i]=candytmkc[i-1]+1;
        for(int i=nums.size()-2;i>=0;i--){if(nums[i]>nums[i+1]) candytmkc[i]=max(candytmkc[i],candytmkc[i+1]+1); res+=candytmkc[i];}
        return res+candytmkc.back();
    }
};