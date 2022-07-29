class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        int left,right,target,leftval,rightval,mainval,i=0;
        while(i<=nums.size()-3){
            left=i+1; right=nums.size()-1;
            target=-nums[i];
            while(left<right){
                if(nums[left]+nums[right]==target){
                    res.push_back({nums[left],nums[right],-target});
                    leftval=nums[left]; rightval=nums[right];
                    while(left<right && leftval==nums[left]) left+=1;
                    while(left<right && rightval==nums[right]) right-=1;
                }else if(nums[left]+nums[right]<target) left+=1;
                else right-=1;
                mainval=nums[i];
            }
            while(i<nums.size() && mainval==nums[i]) i+=1;
        }
        return res;
    }
};