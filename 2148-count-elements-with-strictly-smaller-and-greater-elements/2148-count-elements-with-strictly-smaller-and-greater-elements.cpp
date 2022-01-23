class Solution {
public:
    int countElements(vector<int>& nums) {
        int mx=INT_MIN,mn=INT_MAX;
        for(int i=0;i<nums.size();i++){
            mx=max(mx,nums[i]);
            mn=min(mn,nums[i]);
        }
        int res=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<mx && nums[i]>mn) res++;
        }
        return res;
    }
};