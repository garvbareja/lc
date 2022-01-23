class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        unordered_map<int,int> hash;
        vector<int> ans;
        for(int i=0;i<nums.size();i++) hash[nums[i]]++;
        for(auto it=hash.begin();it!=hash.end();it++){
            if(it->second==1 && !hash.count(it->first-1) && !hash.count(it->first+1)) ans.push_back(it->first);
        }
        return ans;
    }
};