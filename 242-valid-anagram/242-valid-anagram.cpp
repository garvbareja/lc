class Solution {
public:
    bool isAnagram(string &s, string &t) {
        if(s.length()!=t.length()) return false;
        vector<int> hash(26);
        for(int i=0;i<s.length();i++) hash[s[i]-'a']++;
        for(int i=0;i<t.length();i++){
            if(hash[t[i]-'a']) hash[t[i]-'a']--;
            else return false;
        }
        return true;
    }
};