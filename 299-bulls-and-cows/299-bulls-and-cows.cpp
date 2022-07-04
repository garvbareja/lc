class Solution {
public:
    string getHint(string& s, string& g) {
        unordered_map<char,unordered_set<int>> hash; int bulls=0,cows=0;
        for(int i=0;i<s.length();i++) hash[s[i]].insert(i);
        for(int i=0;i<g.length();i++){
            if(hash.count(g[i]) && hash[g[i]].count(i)){
                bulls++; hash[g[i]].erase(i);
                if(hash[g[i]].size()==0) hash.erase(g[i]);
            }
        }
        for(int i=0;i<g.length();i++){
            cout<<hash.count('0');
            if(hash.count(g[i]) && s[i]!=g[i]){
                cows++; hash[g[i]].erase(hash[g[i]].begin());
                if(hash[g[i]].size()==0) hash.erase(g[i]);
            }
        }
        return to_string(bulls)+"A"+to_string(cows)+"B";
    }
};