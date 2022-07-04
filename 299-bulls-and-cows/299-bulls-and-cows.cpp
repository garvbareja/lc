class Solution {
public:
    string getHint(string& s, string& g) {
        unordered_map<char,int> hash; int bulls=0,cows=0;
        for(int i=0;i<s.length();i++){
            if(s[i]==g[i]) bulls++;
            else hash[s[i]]++;
        }
        for(int i=0;i<g.length();i++){
            if(s[i]!=g[i] && hash.count(g[i])){
                hash[g[i]]--;  cows++;
                if(hash[g[i]]==0) hash.erase(g[i]);
            }
        }
        return to_string(bulls)+"A"+to_string(cows)+"B";
    }
};