class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if(nums.size()==1) return nums;
        sort(nums.begin(),nums.end());
        vector<int> dp(nums.size(),1),hash(nums.size()); int maxi=0,lastindex;
        for(int i=0;i<hash.size();i++) hash[i]=i;
        for(int i=1;i<nums.size();i++){
            for(int pi=i-1;pi>=0;pi--){
                if(dp[i]<1+dp[pi] && nums[i]%nums[pi]==0){
                    dp[i]=1+dp[pi];
                    hash[i]=pi;
                }
                if(maxi<dp[i]){
                    maxi=dp[i];
                    lastindex=i;
                }
            }
        }
        vector<int> res;
        while(hash[lastindex]!=lastindex){
            res.push_back(nums[lastindex]);
            lastindex=hash[lastindex];
        }
        res.push_back(nums[lastindex]);
        return res;
    }
};