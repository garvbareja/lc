class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        vector<int> ans(k);
        unordered_map<int,unordered_set<int>> hash;
        for(int i=0;i<logs.size();i++) hash[logs[i][0]].insert(logs[i][1]);
        for(auto it=hash.begin();it!=hash.end();it++) ans[it->second.size()-1]++;
        return ans;
    }
};