class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()) return false;
        vector<int> hash(26);
        for(int i=0;i<t.length();i++) hash[t[i]-'a']++;
        for(int i=0;i<s.length();i++){
            if(!hash[s[i]-'a']) return false;
            hash[s[i]-'a']--;
        }
        return true;
    }
};