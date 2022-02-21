class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hash; int longest=0;
        for(int i=0;i<nums.size();i++) hash.insert(nums[i]);
        for(auto i=hash.begin();i!=hash.end();i++){
            if(!hash.count(*i-1)){
                int curnum=*i;
                int streak=1;
                while(hash.count(curnum+1)){
                    curnum++;
                    streak++;
                }
                longest=max(longest,streak);
            }
        }
        return longest;
    }
};