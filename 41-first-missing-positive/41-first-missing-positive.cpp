class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> hash;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                hash.insert(nums[i]);
            }
        }
        for(int i=1;i<=nums.size()+1;i++){
            if(!hash.count(i)) return i;
        }
        return 1;
    }
};