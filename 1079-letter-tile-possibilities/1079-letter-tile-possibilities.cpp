class Solution {
public:
    vector<int> hash; int res=0;
    void dfs(){
        for(int i=0;i<26;i++){
            if(hash[i]){
                hash[i]--;
                res++;
                dfs();
                hash[i]++;
            }
        }
    }
    
    int numTilePossibilities(string &s){
        hash.resize(26);
        for(int i=0;i<s.length();i++) hash[s[i]-'A']++;
        dfs();
        return res;
    }
};