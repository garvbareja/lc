class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> hash; int j=0,maxx=nums[0],cur=0;
        for(int i=0;i<nums.size();i++){
            cur+=nums[i];
            if(!hash.count(nums[i])) hash.insert(nums[i]);
            else{
                while(nums[j]!=nums[i]){
                    cur-=nums[j];
                    hash.erase(nums[j]);
                    j++;
                }
                cur-=nums[j];
                j++;
            }
            maxx=max(maxx,cur);
        }
        return maxx;
    }
};