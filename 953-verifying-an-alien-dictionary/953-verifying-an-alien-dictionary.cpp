class Solution {
public:
    unordered_map<char,int> hash;
    bool check(string& a,string &b){
        int i=0;
        while(i<a.length() && i<b.length()){
            if(hash[a[i]]<hash[b[i]]) return true;
            if(hash[a[i]]>hash[b[i]]) return false;
            i++;
        }
        if(i==a.length() && i<=b.length()) return true;
        return false;
    }
    
    bool isAlienSorted(vector<string>& words, string order) {
        if(words.size()==1) return true;
        for(int i=0;i<order.length();i++) hash[order[i]]=i;
        for(int i=1;i<words.size();i++){
            if(!check(words[i-1],words[i])) return false;
        }
        return true;
    }
};