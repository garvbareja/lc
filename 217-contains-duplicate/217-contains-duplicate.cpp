class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> hash;
        for(int i=0;i<nums.size();i++) if(hash.count(nums[i])) return true; else hash.insert(nums[i]);
        return false;
    }
};