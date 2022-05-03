class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& nums) {
        vector<vector<int>> res(2);
        map<int,int> loses;
        set<int> winner;
        for(int i=0;i<nums.size();i++) loses[nums[i][1]]++;
        for(int i=0;i<nums.size();i++) if(!loses.count(nums[i][0])) winner.insert(nums[i][0]);
        for(auto it=loses.begin();it!=loses.end();it++) if(it->second==1) res[1].push_back(it->first);
        for(auto it=winner.begin();it!=winner.end();it++) res[0].push_back(*it);
        return res;
    }
};