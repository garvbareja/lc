class Solution {
public:
    int minDeletions(string &s) {
        vector<int> freq(26); unordered_set<int> hash; int res=0;
        for(int i=0;i<s.length();i++) freq[s[i]-'a']++;
        for(int i=0;i<26;i++){
            while(freq[i] && hash.count(freq[i])){
                freq[i]-=1;
                res+=1;
            }
            if(freq[i]) hash.insert(freq[i]);
        }
        return res;
    }
};