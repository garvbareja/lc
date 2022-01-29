class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int> hash; int count=0;
        for(int i=0;i<nums.size();i++){
            if(hash.count(k-nums[i])){
                count++;
                hash[k-nums[i]]--;
                if(!hash[k-nums[i]]) hash.erase(k-nums[i]);
            }else hash[nums[i]]++;
        }
        return count;
    }
};