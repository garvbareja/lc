class Solution {
public:
    int help(int n){
        if(!n) return -1;
        return 1;
    }
    
    int findMaxLength(vector<int>& nums) {
        int sum=0,ans=0;
        unordered_map<int,int> hash; hash[0]=-1;
        for(int i=0;i<nums.size();i++){
            sum+=help(nums[i]);
            if(hash.count(sum)) ans=max(ans,i-hash[sum]);
            else hash[sum]=i;
        }
        return ans;
    }
};