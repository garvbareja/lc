class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& gs) {
        unordered_map<int,vector<int>> hash;
        vector<vector<int>> ans;
        for(int i=0;i<gs.size();i++) hash[gs[i]].push_back(i);
        for(auto it=hash.begin();it!=hash.end();it++){
            for(int i=0;i<it->second.size();i+=it->first){
                ans.push_back(vector<int>(it->second.begin()+i,it->second.begin()+i+it->first));
            }
        }
        return ans;
    }
};