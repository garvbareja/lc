class Solution {
public:
            vector<int> dp;

    bool partition(vector<int>& nums,int i){
        if(i>=nums.size()) return true;
        if(i==nums.size()-1) return false;
        if(dp[i]!=-1) return dp[i];
        bool res=false;
        if(nums[i]==nums[i+1]){
            res=res||partition(nums,i+2);
            if(i+2<nums.size() && nums[i]==nums[i+2]) res=res||partition(nums,i+3);
        }else{
            if(i+2<nums.size() && nums[i+1]==nums[i]+1 && nums[i+2]==nums[i]+2) res=res||partition(nums,i+3);
        }
        return dp[i]=res;
    }
    bool validPartition(vector<int>& nums) {
        dp.resize(nums.size(),-1);
        if(nums.size()==2) return nums[0]==nums[1];
        return partition(nums,0);
    }
};