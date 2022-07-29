class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int t) {
        if(nums.size()<4) return {};
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        int i=0,leftval,rightval,mainval,j,left,right;
        long long target;
        while(i<=nums.size()-4){
            j=i+1;
            while(j<=nums.size()-3){
                left=j+1; right=nums.size()-1;
                target=(long long)t-nums[i]-nums[j];
                while(left<right){
                    if(nums[left]+nums[right]==target){
                        res.push_back({nums[left],nums[right],nums[i],nums[j]});
                        leftval=nums[left]; rightval=nums[right];
                        while(left<right && leftval==nums[left]) left+=1;
                        while(left<right && rightval==nums[right]) right-=1;
                    }else if(nums[left]+nums[right]<target) left+=1;
                    else right-=1;
                }
                mainval=nums[j];
                while(j<=nums.size()-3 && mainval==nums[j]) j+=1;
            }
            mainval=nums[i];
            while(i<=nums.size()-4 && mainval==nums[i]) i+=1;
        }
        return res;
    }
};