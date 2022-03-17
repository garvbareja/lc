class Solution {
public:
    vector<char> map;
    vector<char> rev_map;
    bool biject(string &a,string &b){
        fill(map.begin(),map.end(),'#');
        fill(rev_map.begin(),rev_map.end(),'#');
        for(int i=0;i<a.length();i++){
            if(map[b[i]-'a']!=a[i]){
                if(map[b[i]-'a']=='#') map[b[i]-'a']=a[i];
                else return false;
            }
            if(rev_map[a[i]-'a']!=b[i]){
                if(rev_map[a[i]-'a']=='#') rev_map[a[i]-'a']=b[i];
                else return false;
            }
        }
        return true;
    }
    
    vector<string> findAndReplacePattern(vector<string>& words, string &s) {
        vector<string> res; map.resize(26); rev_map.resize(26);
        for(int i=0;i<words.size();i++){
            if(biject(words[i],s)) res.push_back(words[i]);
        }
        return res;
    }
};