class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count=0,prefix=0;
        unordered_map<int,int> hash; hash[0]++;
        for(int i=0;i<nums.size();i++){
            prefix+=nums[i];
            if(hash.count(prefix-k)) count+=hash[prefix-k];
            hash[prefix]++;
        }
        return count;
    }
};