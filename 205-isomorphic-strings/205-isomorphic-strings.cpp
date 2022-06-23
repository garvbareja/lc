class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> hash(128,-1);
        unordered_set<char> vis;
        for(int i=0;i<s.length();i++){
                if(hash[s[i]]==-1){
                    hash[s[i]]=(int)t[i];
                    if(vis.count(t[i])) return false;
                    vis.insert(t[i]);
                }else{
                    if((char)hash[s[i]]!=t[i]) return false;
                }
        }
        return true;
    }
};