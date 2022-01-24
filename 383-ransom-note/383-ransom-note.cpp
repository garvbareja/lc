class Solution {
public:
    bool canConstruct(string r, string m) {
        vector<int> hash(26);
        for(int i=0;i<m.length();i++) hash[m[i]-'a']++;
        for(int i=0;i<r.length();i++) if(!hash[r[i]-'a']--) return false;
        return true;
    }
};