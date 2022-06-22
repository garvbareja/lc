class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> hash;
        string temp;
        for(int i=0;i<strs.size();i++){
            temp=strs[i];
            sort(temp.begin(),temp.end());
            hash[temp].push_back(strs[i]);
        }
        vector<vector<string>> res;
        for(auto it=hash.begin();it!=hash.end();it++){
            res.push_back(it->second);
        }
        return res;
    }
};